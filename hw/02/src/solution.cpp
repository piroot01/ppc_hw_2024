#include "MHD/solution.h"
#include "MHD/doprava.hpp"
#include <charconv>
#include <iomanip>
#include <sstream>


NetworkInterface::NetworkInterface(const Network&& network) :
    Network(std::move(network))
{
}

void NetworkInterface::print_timetable(const std::string& stop) const
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

void NetworkInterface::print_table(const Line& line, const std::string& stop_name, const uint32_t line_num) const
{
    //int h, m ,s;
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
        if (i == 38 || i == 39)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;
    std::cout << "| "<< "To: "<< setw(32) << left << line.stops.back() << " || To: " << setw(32) << left << line.stops.front()<< " |" << endl;
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 38 || i == 39 || i == 4 || i == 44)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;

    // prints the body of the schedule
    for (uint32_t h = 0; h < 24; ++h)
    {
        auto foundedStop = std::find(line.stops.begin(), line.stops.end(), stop_name);
        std::string times_fwd = this->get_times(line.conns_fwd, std::distance(line.stops.begin(), foundedStop), h);
        std::string times_bwd = this->get_times(line.conns_bwd, std::distance(line.stops.begin(), foundedStop), h);
        std::cout << "| " 
                  << std::setw(2) 
                  << std::right 
                  << std::setfill('0') 
                  << h 
                  << " | " 
                  << std::setw(32) 
                  << std::left 
                  << std::setfill(' ') 
                  << times_fwd 
                  << "|| "
                  << std::setw(2)
                  << std::right
                  << std::setfill('0')
                  << h
                  << " | "
                  << std::setw(32)
                  << std::left
                  << std::setfill(' ')
                  << times_bwd
                  << "|\n";
    }

    // last line
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 38 || i == 39 || i == 4 || i == 44)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;
}


std::string NetworkInterface::get_times(const std::vector<PlanConn>& conn, const uint32_t stop_index, const uint32_t hour) const
{
    std::stringstream ss;
    int32_t hh, mm, s;
    for (const auto& plann_conn : conn)
    {
        auto time = plann_conn[stop_index].ti;
        if ((uint32_t)time.gets() >= hour * 3600 and (uint32_t)time.gets() < (hour + 1) * 3600)
        {
            time.gett(hh, mm, s);
            ss << std::setw(2) << std::right << std::setfill('0') << mm << std::setfill(' ') << " ";
        }
    }
    return ss.str();
}

void NetworkInterface::line_routing(void) const
{
    for (auto iter = lines.begin(); iter < lines.end(); ++iter)
        this->print_line(*iter, std::distance(lines.begin(), iter));
}

void NetworkInterface::print_line(const Line& line, const uint32_t line_num) const
{
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        std::cout << "-" ;
    }
    std::cout << "+"<< std::endl;
    std::cout << "| "
              << "Line: "
              << std::setw(71)
              << std::left
              << std::setfill(' ')
              << line_num
              << "|\n";

    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 38 || i == 39 || i == 3 || i == 43 || i == 8 || i == 48)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;

    std::cout << "| d | rT | ==>                         || d | rT | <==                         |\n";
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 38 || i == 39 || i == 3 || i == 43 || i == 8 || i == 48)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;

    auto line_data = this->load_line_data(line);
    auto fwd_iter = line_data.begin();
    auto bwd_iter = line_data.rbegin();
    uint32_t fwd_accumulator = 0;
    uint32_t bwd_accumulator = 0;

    const uint32_t stop_num = line.stops.size();
    for (uint32_t i = 0; i < stop_num; ++i)
    {
        fwd_accumulator += fwd_iter->time_from_prev_stop;
        bwd_accumulator += bwd_iter->time_to_next_stop;
        print_line_row(fwd_iter, bwd_iter, fwd_accumulator, bwd_accumulator);
        fwd_iter++;
        bwd_iter++;
    }
    std::cout << "+";
    for (int i = 0; i < 78; i++)
    {
        if (i == 38 || i == 39 || i == 3 || i == 43 || i == 8 || i == 48)
        {
            std::cout << "+";
            continue;
        }
        std::cout << "-" ;
    }
    std::cout << "+" << endl;
}

void NetworkInterface::print_line_row(const std::vector<StopTimeDiff>::const_iterator& fwd_iter, const std::vector<StopTimeDiff>::const_reverse_iterator& bwd_iter, const uint32_t fwd_accumulator, const uint32_t bwd_accumulator) const
{
    std::cout << "| "
              << fwd_iter->time_from_prev_stop / 60
              << " | "
              << std::setfill('0')
              << std::right
              << std::setw(2)
              << fwd_accumulator / 60
              << " | "
              << std::setfill(' ')
              << std::left
              << std::setw(28)
              << fwd_iter->stop_name
              << "|| "
              << bwd_iter->time_to_next_stop / 60
              << " | "
              << std::setfill('0')
              << std::right
              << std::setw(2)
              << bwd_accumulator / 60
              << " | "
              << std::setfill(' ')
              << std::left
              << std::setw(28)
              << bwd_iter->stop_name
              << "|\n";
}

std::vector<StopTimeDiff> NetworkInterface::load_line_data(const Line& line) const
{
    std::vector<StopTimeDiff> line_data;
    const uint32_t stop_num = line.stops.size();
    for (std::size_t index = 0; index < stop_num; ++index)
    {
        StopTimeDiff stop_time_diff;
        stop_time_diff.stop_name = line.stops.at(index);
        if (index > 0)
        {
            stop_time_diff.time_from_prev_stop = line.conns_fwd.at(0).at(index).ti.gets() - line.conns_fwd.at(0).at(index - 1).ti.gets();
            if (index < stop_num - 1)
                stop_time_diff.time_to_next_stop = line.conns_fwd.at(0).at(index + 1).ti.gets() - line.conns_fwd.at(0).at(index).ti.gets();
        } else
            if (index < stop_num - 1)
                stop_time_diff.time_to_next_stop = line.conns_fwd.at(0).at(index + 1).ti.gets() - line.conns_fwd.at(0).at(index).ti.gets();
        line_data.push_back(stop_time_diff);
    }
    return line_data;
}


void NetworkInterface::fill_stats(DriverStats& driverStats) const
{
    uint32_t line_num = 0;
    for (const auto& line : lines)
    {
        for (const auto& conn : line.conns_fwd)
        {
            auto driverEntryIter = std::find_if(driverStats.m_database.begin(), driverStats.m_database.end(), [&] (const DriverEntry& entry) -> bool {
                return entry.driver_name == conn.drv.name;
            });
            driverEntryIter->line_num = line_num;
            if (driverEntryIter != driverStats.m_database.end() and driverEntryIter->ride_count == -1)
            {
                driverEntryIter->ride_count++;
                driverEntryIter->station_count++;
            }
            driverEntryIter->ride_count++;
            driverEntryIter->station_count += conn.size();
        }
        for (const auto& conn : line.conns_bwd)
        {
            auto driverEntryIter = std::find_if(driverStats.m_database.begin(), driverStats.m_database.end(), [&] (const DriverEntry& entry) -> bool {
                return entry.driver_name == conn.drv.name;
            });
            driverEntryIter->line_num = line_num;
            if (driverEntryIter != driverStats.m_database.end() and driverEntryIter->ride_count == -1)
            {
                driverEntryIter->ride_count++;
                driverEntryIter->station_count++;
            }
            driverEntryIter->ride_count++;
            driverEntryIter->station_count += conn.size();
        }
        line_num++;
    }
}


void DriverStats::print_driver_stats(void)
{
    std::cout << "+----------------------+---+----+-----+\n"
              << "| Driver Name          | L | nC | nSt |\n"
              << "+----------------------+---+----+-----+\n";
    std::stable_sort(m_database.begin(), m_database.end(), [&] (const DriverEntry& a, const DriverEntry& b) -> bool {
        return a.station_count > b.station_count;
    });
    for (const auto& entry : m_database)
    {
        std::cout << "| "
                  << std::setfill(' ')
                  << std::left
                  << std::setw(21)
                  << entry.driver_name
                  << "| "
                  << ((entry.line_num == -1) ? "X" : std::to_string(entry.line_num))
                  << " | "
                  << std::right
                  << std::setw(2)
                  << ((entry.ride_count == -1) ? "XX" : std::to_string(entry.ride_count))
                  << " | "
                  << std::right
                  << std::setw(3)
                  << ((entry.station_count == -1) ? "XXX" : std::to_string(entry.station_count))
                  << " |\n";
    }
    std::cout << "+----------------------+---+----+-----+\n";
}


DriverStats::DriverStats(const DriverList& driver_list)
{
    for (const auto& driver_name : driver_list)
    {
        DriverEntry driverEntry;
        driverEntry.driver_name = driver_name.name;
        m_database.push_back(driverEntry);
    }
}
