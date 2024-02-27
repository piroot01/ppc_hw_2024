#include <Config.h>


Config::Config() :
    m_min(0), m_max(0), m_width(0), m_align(Align::LEFT)
{
}


Config::Config(const int32_t min, const int32_t max, const uint32_t width, const Align align) :
    m_min(min), m_max(max), m_width(width), m_align(align)
{
}
