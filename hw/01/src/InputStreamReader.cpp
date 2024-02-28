#include <InputStreamReader.h>


void InputStreamReader::load()
{
    bool eof = false;
    std::string line;
    while (!eof)
    {
        std::getline(std::cin, line);
        if (line.empty())
            eof = true;
        m_data.push_back(line);
    }
    m_data.pop_back();
}

void InputStreamReader::printStream()
{
    for (const auto& line : m_data)
        std::cout << line << '\n';
}
