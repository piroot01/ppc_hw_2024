#ifndef InputPreparator_INCLUDED
#define InputPreparator_INCLUDED


#include <InputStreamReader.h>
#include <ConfigReader.h>
#include <TableReader.h>


#include <string>
#include <algorithm>
#include <cstdint>


class InputPreparator
{
public:
    void load();
    void split();
    bool prepareConfig(ConfigReader& reader);
    bool prepareTable(TableReader& reader);

private:
    InputStreamReader m_inputStreamReader;
    uint32_t m_delimIndex = {0};
    std::string m_streamDelim = "=";

};


inline void InputPreparator::load()
{
    m_inputStreamReader.load();
    m_inputStreamReader.printStream();
}


#endif
