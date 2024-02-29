#ifndef MAIN_HPP
#define MAIN_HPP


#include <string>
#include <vector>
#include <cstdint>
#include "parse.hpp"


enum class Align
{
    LEFT,
    RIGHT,
};


using table_t = std::vector<std::vector<int>>;


void printConfig(const std::vector<config_t>& configVect);


void printTableLine(const uint32_t collNum, const uint32_t collWidth);

void printTableHeader(const uint32_t collNum, const uint32_t collWidth, const Align align);


void printTableBody(const uint32_t collNum, const uint32_t collWidth, const Align align, const std::vector<int32_t>& row, const uint32_t index);


void printTable(const std::vector<config_t>& config, const table_t& table);


int32_t getParamFromConfig(const std::vector<config_t>& config, const std::string& configName);


void checkConfig(std::vector<config_t>& config);

bool checkTable(const std::vector<config_t>& config, const table_t& table);

#endif
