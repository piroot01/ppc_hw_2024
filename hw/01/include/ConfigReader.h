#ifndef ConfigReadder_INCLUDED
#define ConfigReadder_INCLUDED


#include <Config.h>
#include <InputStreamReader.h>
#include <iostream>
#include <fstream>
#include <string>


class ConfigErrorReport
{
public:
    void printError();

    bool outOfRange = {false};
    bool invalidInput = {false};
    bool invalidConfig = {false};

};


class ConfigReader
{
public:
    ConfigReader(Config& config);
    bool read(const InputStreamReader& inputStreamReader);

private:
    Config& m_config;
    ConfigErrorReport m_configErrorReport;
    bool m_readFromFile;
    std::string m_fileName;

    const char configDelim = '.';
    const char valueDelim = '=';

};


#endif
