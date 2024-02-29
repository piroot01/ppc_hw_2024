#include <InputPreparator.h>


void InputPreparator::split()
{
    std::string line;
    while (line != m_streamDelim)
    {
        m_inputStreamReader.getLine(m_delimIndex, line);
        m_delimIndex++;
    }
    m_delimIndex--;
}


bool InputPreparator::prepareConfig(ConfigReader& configReader)
{
    inputFormat_t configData;
    std::string line;
    for (uint32_t lineNum = 0; lineNum < m_delimIndex; ++lineNum)
    {
        m_inputStreamReader.getLine(lineNum, line);
        configData.push_back(line);
    }
    return configReader.read(configData);
}


bool InputPreparator::prepareTable(TableReader& tableReader)
{
    inputFormat_t tableData;
    std::string line;
    for (uint32_t lineNum = m_delimIndex + 1; lineNum < m_inputStreamReader.getDataLineCount(); ++lineNum)
    {
        m_inputStreamReader.getLine(lineNum, line);
        tableData.push_back(line);
    }
    bool returnValue = tableReader.read(std::move(tableData));
    return true;
}
