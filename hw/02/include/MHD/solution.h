#ifndef solution_INCLUDED
#define solution_INCLUDED


#include "MHD/doprava.hpp"
#include <vector>


class NetworkInterface : public Network
{
public:
    NetworkInterface(const Network&& network);

    void print_timetable(const std::string& stop);

    void print_table(const Line& line, const std::string& stop_name, const uint32_t line_num);

private:
    std::string get_times(const std::vector<PlanConn>& conn, const uint32_t stop_index, const uint32_t hour);

};



#endif
