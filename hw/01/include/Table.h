#ifndef Table_INCLUDED
#define Table_INCLUDED


#include <cstdint>
#include <iostream>
#include <vector>


using tableDataType_t = int32_t;
using tableRow_t = std::vector<tableDataType_t>;
using table_t = std::vector<tableRow_t>;


class Table
{
public:
    Table();
    void printTable() const;

private:
    table_t m_table;

public:
    friend class TableReader;

};


#endif
