#include <TableReader.h>


TableReader::TableReader(Table& table) :
    m_table(table)
{
}


bool TableReader::read(const inputFormat_t&& input)
{
    const auto lineCount = input.size();
    std::string line;
    while (m_currentRow < lineCount)
    {
        processLine(input.at(m_currentRow));
        m_currentRow++;
    }
    return true;
}

void TableReader::processLine(const std::string& line)
{
    tableRow_t row;
    std::stringstream stream(line);
    std::string cell;
    uint32_t cellValue;
    while (std::getline(stream, cell, m_tableDelim))
    {
        try
        {
            cellValue = std::stoi(cell);
        }
        catch (...)
        {
            try
            {
                cellValue = parseSum(cell, row);
            }
            catch (...)
            {
                std::cout << "sum parsing error\n"; 
            }
        }
        std::cout << cellValue << '\n';
        row.push_back(cellValue);
    }
    m_table.m_table.push_back(row);
}


int32_t TableReader::parseSum(const std::string& cell, const tableRow_t& row)
{
    int32_t result = 0;
    uint32_t sumDescIndex = cell.find(m_sumDesc);
    // extract the coords of the sum
    uint32_t startIndex = (uint32_t)cell.substr(sumDescIndex + 4, 1)[0] - 65;
    uint32_t endIndex = (uint32_t)cell.substr(sumDescIndex + 6, 1)[0] - 65;
    for (uint32_t index = startIndex; index < endIndex + 1; ++index)
    {
        result += row.at(index);
    }
    return result;
}
