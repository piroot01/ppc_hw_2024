#ifndef TableReadder_INCLUDED
#define TableReadder_INCLUDED


#include <Table.h>
#include <InputFormat.h>


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class TableErrorReport
{
public:

};


class TableReader
{
public:
    TableReader(Table& config);
    bool read(const inputFormat_t& input);

private:
    void processLine(const std::string& line);
    int32_t parseSum(const std::string& cell);

private:
    Table& m_table;
    uint32_t m_currentRow = {0};
    TableErrorReport m_configErrorReport;

    const char m_tableDelim = ';';
    const std::string m_sumDesc = "SUM";

};


#endif
