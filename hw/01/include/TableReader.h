#ifndef TableReadder_INCLUDED
#define TableReadder_INCLUDED


#include <Table.h>
#include <InputFormat.h>


#include <iostream>
#include <fstream>
#include <string>


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
    Table& m_table;
    TableErrorReport m_configErrorReport;

};


#endif
