#include <Config.h>
#include <Table.h>
#include <ConfigReader.h>
#include <InputPreparator.h>

int main()
{
    InputPreparator inputPreparator;

    Config config;
    ConfigReader configReader(config);
    Table table;
    TableReader tableReader(table);

    inputPreparator.load();
    inputPreparator.split();
    inputPreparator.prepareConfig(configReader);
    inputPreparator.prepareTable(tableReader);

    //table.printTable();


    //config.printConfig();

    return 0;
}
