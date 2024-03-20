#include "MHD/solution.h"
#include "MHD/doprava.hpp"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iterator>
#include <set>


NetworkInterface::NetworkInterface(const Network&& network) :
    Network(std::move(network))
{
}

void NetworkInterface::print_timetable(const std::string& stop)
{
    uint32_t line_num = 0;
    for (const auto& line : lines)
    {
        auto foundedStop = std::find(line.stops.begin(), line.stops.end(), stop);
        if (foundedStop != line.stops.end())
            this->print_table(line, *foundedStop, line_num);
        line_num++;
    }
}

void NetworkInterface::print_table(const Line& line, const std::string& stop_name, const uint32_t line_num)
{
    int h, m ,s;
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        std::cout << "-" ;
    }
    std::cout << "+"<< std::endl;
    std::cout << "| "<< setw(38) << left << stop_name;
    std::cout << setw(37) << right << "Line: " << line_num << " |" << endl; 
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 39 || i == 40)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;
    std::cout << "| "<< "To: "<< setw(33) << left << line.stops.back() << " || To: " << setw(32) << left << line.stops.front()<< "|" << endl;
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 39 || i == 40 || i == 4 || i == 45)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;
    for (uint32_t h = 0; h < 24; ++h)
    {
        auto foundedStop = std::find(line.stops.begin(), line.stops.end(), stop_name);
        std::string times_fwd = this->get_times(line.conns_fwd, std::distance(line.stops.begin(), foundedStop), h);
        std::cout << "| " << h << " | " << times_fwd << '\n';
    }
}


std::string NetworkInterface::get_times(const std::vector<PlanConn>& conn, const uint32_t stop_index, const uint32_t hour)
{
    std::string times;
    int32_t hh, mm, ss;
    for (const auto& plann_conn : conn)
    {
        auto time = plann_conn[stop_index].ti;
        if (time.gets() >= hour * 3600 and time.gets() < (hour + 1) * 3600)
        {
            time.gett(hh, mm, ss);
            times += std::to_string(mm);
            times += std::string(" ");
        }
    }
    return times;
}
