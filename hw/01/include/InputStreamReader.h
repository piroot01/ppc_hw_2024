#ifndef InputStreamReader_INCLUDED
#define InputStreamReader_INCLUDED


#include <vector>
#include <string>
#include <iostream>
#include <cstdint>


class InputStreamReader
{
public:
    void load();
    void printStream();
    constexpr uint32_t getDataLineCount() const;
    bool getLine(const uint32_t lineNum, std::string& string) const;

private:
    std::vector<std::string> m_data;

};


constexpr inline uint32_t InputStreamReader::getDataLineCount() const
{
    return m_data.size();
}


inline bool InputStreamReader::getLine(const uint32_t lineNum, std::string& string) const
{
    if (lineNum >= m_data.size())
        return false;
    string = m_data[lineNum];
    return true;
}


#endif
