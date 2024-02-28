#ifndef Config_INCLUDED
#define Config_INCLUDED


#include <cstdint>
#include <iostream>


enum class Align
{
    LEFT,
    RIGHT

};


class Config
{
public:
    Config();
    Config(const int32_t min, const int32_t max, const uint32_t width, const Align align);
    void printConfig() const;


private:
    int32_t m_min;
    int32_t m_max;
    int32_t m_width;
    Align m_align;

public:
    friend class ConfigReader;

};


#endif
