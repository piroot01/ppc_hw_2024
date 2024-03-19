#ifndef solution_INCLUDED
#define solution_INCLUDED


#include "MHD/doprava.hpp"


class NetworkInterface : public Network
{
public:
    NetworkInterface(const Network&& network);

    void print_timetable(const std::string& stop);

};




#endif
