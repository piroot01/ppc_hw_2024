#include <Table.h>


Table::Table() = default;


void Table::printTable() const
{
    for (const auto& row : m_table)
    {
        for (const auto cell : row)
            std::cout << cell << ", ";
        std::cout << '\n';
    }
}
