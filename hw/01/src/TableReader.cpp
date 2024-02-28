#include <TableReader.h>


TableReader::TableReader(Table& table) :
    m_table(table)
{
}


bool TableReader::read(const inputFormat_t& input)
{
    const auto lineCount = input.size();
    std::string line;
    for (uint32_t lineNum = 0; lineNum < lineCount; ++lineNum)
    {
        processLine(input.at(lineNum));
    }
}

void TableReader::processLine(const std::string& line)
{
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
                cellValue = parseSum(cell);
            }
            catch (...)
            {
                std::cout << "sum parsing error\n"; 
            }
        }
        m_table.m_table[m_currentRow].push_back(cellValue);
    }
}


int32_t TableReader::parseSum(const std::string& cell)
{
    int32_t result = 0;
    uint32_t sumDescIndex = cell.find(m_sumDesc);
    // extract the coords of the sum
    uint32_t startIndex = (uint32_t)cell.substr(sumDescIndex + 4, 1)[0] - 65;
    uint32_t endIndex = (uint32_t)cell.substr(sumDescIndex + 6, 1)[0] - 65;
    for (uint32_t index = startIndex; index < endIndex; ++index)
        result += m_table.m_table[m_currentRow].at(index);
    return result;
}
