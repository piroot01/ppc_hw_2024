#include "MHD/solution.h"
#include "MHD/doprava.hpp"


NetworkInterface::NetworkInterface(const Network&& network) :
    Network(std::move(network))
{
}

void NetworkInterface::print_timetable(const std::string& stop)
{
    for (const auto& line : lines)
    {
        auto foundedStop = std::find(line.stops.begin(), line.stops.end(), stop);
        //this->print_table(line, *foundedStop, std::distance(line.stops.begin(), foundedStop));
        
    }
}
