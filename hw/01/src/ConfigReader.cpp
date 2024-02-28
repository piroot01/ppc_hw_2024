#include <ConfigReader.h>


void ConfigErrorReport::printError()
{
    if (outOfRange)
        std::cout << "Out of range\n";
    else if (invalidInput)
        std::cout << "Invalid input\n";
    else if (invalidConfig)
        std::cout << "Invalid configuration\n";
}


ConfigReader::ConfigReader(Config& config) :
    m_config(config)
{
}


bool ConfigReader::read(const inputFormat_t& input)
{
    const auto lineCount = input.size();
    std::string line;
    for (uint32_t lineNum = 0; lineNum < lineCount; ++lineNum)
    {
        line = input.at(lineNum);
        const std::size_t dotPos = line.find(configDelim);
        const std::size_t valuePos = line.find(valueDelim);
        if (line.substr(0, dotPos) == std::string("config"))
        {
            const std::string configName = line.substr(dotPos + 1, valuePos - dotPos - 1);
            const std::string configValue = line.substr(valuePos + 1, line.size());
            if (configName == "min")
                m_config.m_min = std::stoi(configValue);
            else if (configName == "max")
                m_config.m_max = std::stoi(configValue);
            else if (configName == "width")
                m_config.m_width = std::stoi(configValue);
            else if (configName == "align")
            {
                if (configValue == "left")
                    m_config.m_align = Align::LEFT;
                else if (configValue == "right")
                    m_config.m_align = Align::RIGHT;
                else
                {
                    m_configErrorReport.invalidInput = true;
                    return false;
                }
            }
            else
            {
                m_configErrorReport.invalidInput = true;
                return false;
            }
        }
    }
    return false;
}
