#include <Config.h>
#include <ConfigReader.h>
#include <InputStreamReader.h>

int main()
{
    InputStreamReader inputStreamReader;
    inputStreamReader.load();

    Config config;
    ConfigReader configReader(config);
    configReader.read(inputStreamReader);
    config.printConfig();

    return 0;
}
