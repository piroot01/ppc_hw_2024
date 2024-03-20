#ifndef solution_INCLUDED
#define solution_INCLUDED


#include "MHD/doprava.hpp"
#include <cstdint>
#include <iterator>
#include <vector>


class StopTimeDiff
{
public:
    std::string stop_name;
    uint32_t time_from_prev_stop = {0};
    uint32_t time_to_next_stop = {0};

};


class DriverEntry
{
public:
    std::string driver_name;
    int32_t line_num = {-1};
    int32_t ride_count = {-1};
    int32_t station_count = {-1};

};


class DriverStats
{
public:
    DriverStats(const DriverList& driver_list);

    void print_driver_stats(void);

private:
    std::vector<DriverEntry> m_database;

public:
    friend class NetworkInterface;

};


class NetworkInterface : public Network
{
public:
    NetworkInterface(const Network&& network);

    void print_timetable(const std::string& stop) const;

    void print_table(const Line& line, const std::string& stop_name, const uint32_t line_num) const;

    void line_routing(void) const;

    void fill_stats(DriverStats& driverStats) const;

private:
    std::string get_times(const std::vector<PlanConn>& conn, const uint32_t stop_index, const uint32_t hour) const;

    void print_line(const Line& line, const uint32_t line_num) const;

    std::vector<StopTimeDiff> load_line_data(const Line& line) const;

    void print_line_row(const std::vector<StopTimeDiff>::const_iterator& fwd_iter, const std::vector<StopTimeDiff>::const_reverse_iterator& bwd_iter, const uint32_t fwd_accumulator, const uint32_t bwd_accumulator) const;

};



#endif
