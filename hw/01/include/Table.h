#ifndef Table_INCLUDED
#define Table_INCLUDED


#include <cstdint>
#include <iostream>
#include <vector>


using table_t = std::vector<std::vector<int32_t>>;


class Table
{
public:
    Table();

private:
    table_t m_table;

public:
    friend class TableReader;

};


#endif
