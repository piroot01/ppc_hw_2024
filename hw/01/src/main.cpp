#include <Config.h>
#include <ConfigReader.h>
#include <InputPreparator.h>

int main()
{
    InputPreparator inputPreparator;

    Config config;
    ConfigReader configReader(config);

    inputPreparator.load();
    inputPreparator.split();
    inputPreparator.prepareConfig(configReader);

    //config.printConfig();

    return 0;
}
