#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <iomanip>
#include "main.hpp"
#include "parse.hpp"

#define notFound -9999

int main(){  
    // variable for decoded config
    config_t config;
    std::vector<config_t> configVect;
    std::string line;
    do{
        std::getline(std::cin, line);

        config = getConfig(line);
        if(config.valid){
           configVect.push_back(config);
        }
    }
    while(config.valid);
    
    table_t values;

    while(std::getline(std::cin, line)){
        std::stringstream ss(line);
        std::vector<int> row;
        std::string cell;
        int number;

        while (std::getline(ss,cell, ';')) {
            try {   // if loaded cell is number
                number = std::stoi(cell);
				row.push_back(number);
            }
            catch(const std::exception& e)
            {
                try
                {
                    sum_t sum = getSum(cell, row);
                    if (sum.valid == false)
                    {
                        throw std::runtime_error("Invalid input");
                    }
                    row.push_back(sum.value);
                }
                catch (...)
                {
                    std::cerr << "Invalid input\n";
                    return 101;
                }
            }
        }
        values.push_back(row);     
    }

    checkConfig(configVect);
    if (getParamFromConfig(configVect, "width") <= 0)
    {
        std::cerr << "Invalid configuration\n";
        return 102;
    }
    if (getParamFromConfig(configVect, "stretch") == notFound and getParamFromConfig(configVect, "header") == notFound)
    {
        if ((uint32_t)getParamFromConfig(configVect, "width") < getMaxNumSize(values))
            {
            std::cerr << "Cell is too short\n";
            return 103;
        }
        if (!checkTable(configVect, values))
        {
            std::cerr << "Out of range\n";
            return 100;
        }
    }
    printConfig(configVect);
    std::cout << '\n';
    printTable(configVect, values);

    return 0;
}


void printConfig(const std::vector<config_t>& configVect)
{
    std::cout << "config.min=" << getParamFromConfig(configVect, "min") << '\n';
    std::cout << "config.max=" << getParamFromConfig(configVect, "max")<< '\n';
    std::cout << "config.width=" << getParamFromConfig(configVect, "width")<< '\n';
    std::cout << "config.align=";
    for (const config_t& config : configVect)
    {
        if (config.type == "align")
        {
            std::cout << config.value << '\n';
            break;
        }
    }

    if (getParamFromConfig(configVect, "stretch") != notFound)
    {
        std::cout << "config.stretch=" << getParamFromConfig(configVect, "stretch") << '\n';
    }

    if (getParamFromConfig(configVect, "header") != notFound)
    {
        std::cout << "config.header=" << getParamFromConfig(configVect, "header") << '\n';
    }
}


void printTableLine(const uint32_t collNum, const uint32_t collWidth)
{
    std::cout << '+';
    for (uint32_t i = 0; i < collNum; i++)
    {
        for (uint32_t j = 0; j < collWidth; j++)
        {
            std::cout << '-';
        }
        std::cout << '+';
    }
    std::cout << '\n';
}


void printTableHeader(const uint32_t collNum, const uint32_t collWidth, const Align align)
{
    std::cout << '|' << std::setw(collWidth + 1) << std::right << '|';
    for (uint32_t i = 0; i < collNum - 1; i++)
    {
        if (align == Align::LEFT)
        {
            std::string cellValue = " ";
            cellValue.append(1, (char)(i + 65));
            std::cout << std::setw(collWidth) << std::left << cellValue;
        }
        else
            std::cout << std::setw(collWidth - 1) << (char)(i + 65) << ' ';
        std::cout << '|';
    }
    std::cout << '\n';
}


void printTableBody(const uint32_t collNum, const uint32_t collWidth, const Align align, const std::vector<int32_t>& row, const uint32_t index, const bool printHeader)
{
    // prints the first cell of the row
    if (printHeader)
    {
        if (align == Align::LEFT)
        {
            std::string cellValue = " ";
            cellValue += std::to_string(index);
            std::cout << "|" << std::setw(collWidth) << std::left << cellValue;
        }
        else
            std::cout << "|" << std::setw(collWidth - 1) << index << ' ';
        std::cout << '|';
    }
    else
    {
        std::cout << '|';
    }
    

    for (uint32_t i = 0; i < collNum - 1; i++)
    {
        if (align == Align::LEFT)
        {
            std::string cellValue = " ";
            if (i < row.size())
            {
                if (std::to_string(row[i]).size() > collWidth - 2)
                    cellValue += std::string(collWidth - 2, '#');
                else
                    cellValue += std::to_string(row[i]);
            }
            std::cout << std::setw(collWidth) << std::left << cellValue;
        }
        else
        {
            std::string cellValue = "";
            if (i < row.size())
            {
                if (std::to_string(row[i]).size() > collWidth - 2)
                    cellValue += std::string(collWidth - 2, '#');
                else
                    cellValue += std::to_string(row[i]);
            }
            std::cout << std::setw(collWidth - 1) << cellValue << ' ';
        }
        std::cout << '|';
    }
    std::cout << '\n';
}


void printTable(const std::vector<config_t>& config, const table_t& table)
{
    Align tableAlign;

    for (const config_t& config : config)
    {
        if (config.type == "align")
        {
            if (config.value == "left")
                tableAlign = Align::LEFT;
            else if (config.value == "right")
                tableAlign = Align::RIGHT;
            break;
        }
    }

    //int32_t min = getParamFromConfig(config, "min");
    //int32_t max = getParamFromConfig(config, "max");
    uint32_t width = getParamFromConfig(config, "width");

    uint32_t maxRowLength = 0;
    for (const std::vector<int>& row : table)
    {
        if (row.size() > maxRowLength)
            maxRowLength = row.size();
    }

    // adjust coll width
    if (getParamFromConfig(config, "stretch") == 1)
        width = getMaxNumSize(table);

    bool printHeader = getParamFromConfig(config, "header");

    if (printHeader)
    {
        printTableLine(maxRowLength + 1, width + 2);
        printTableHeader(maxRowLength + 1, width + 2, tableAlign);
    }

    printTableLine((printHeader) ? maxRowLength + 1 : maxRowLength, width + 2);
    uint32_t index = 1;

    for (const auto& row : table)
    {
        printTableBody(maxRowLength + 1, width + 2, tableAlign, row, index, printHeader);
        printTableLine((printHeader) ? maxRowLength + 1 : maxRowLength, width + 2);
        index++;
    }
}


int32_t getParamFromConfig(const std::vector<config_t>& config, const std::string& configName)
{
    for (const config_t& config : config)
    {
        if (config.type == configName)
        {
            int32_t value;
            try
            {
                value = std::stoi(config.value);
                return value;
            }
            catch (...)
            {
                return 0;
            }
        }
    }
    return notFound;
}


void checkConfig(std::vector<config_t>& config)
{
    if (getParamFromConfig(config, "min") == notFound)
    {
        config_t configVal = {"min", "-99", true};
        config.push_back(configVal);
    }
    if (getParamFromConfig(config, "max") == notFound)
    {
        config_t configVal = {"max", "100", true};
        config.push_back(configVal);
    }
    if (getParamFromConfig(config, "width") == notFound)
    {
        config_t configVal = {"width", "3", true};
        config.push_back(configVal);
    }
    if (getParamFromConfig(config, "align") == notFound)
    {
        config_t configVal = {"align", "left", true};
        config.push_back(configVal);
    }
}


bool checkTable(const std::vector<config_t>& config, const table_t& table)
{
    const int32_t min = getParamFromConfig(config, "min");
    const int32_t max = getParamFromConfig(config, "max");

    for (const auto& row : table)
    {
        for (const auto& cell : row)
        {
            if (!(cell <= max and cell >= min))
                return false;
        }
    }
    return true;
}


uint32_t getMaxNumSize(const table_t& table)
{
    uint32_t maxNumSize = 0;
    for (const std::vector<int>& row : table)
    {
        for (const auto cell : row)
        {
            if (std::to_string(cell).size() > maxNumSize)
                maxNumSize = std::to_string(cell).size();
        }
    }
    return maxNumSize;
}
