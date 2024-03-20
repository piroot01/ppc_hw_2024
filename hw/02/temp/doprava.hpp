#ifndef DOPRAVA_H
#define DOPRAVA_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// exception for read file - do not modify
struct file_corrupt : public std::exception
{
    const char *what() const throw() { return "file_corrupt"; }
};

// Direction of connection/departure
enum class Lndir
{
    fwd,
    bwd
};



class Time
{
    int seconds; // seconds after midnight
public:
    Time(int ss = 0);                           // initialize by seconds after midnight: seconds(ss){};
    Time(int hh, int mm, int ss = 0);           // initialize by hours, minutes seconds
    Time(const Time &tt);                       // copy-constructor
    int gets() const;                           // get seconds after midnight // {return ss;}
    void gett(int &hh, int &mm, int &ss) const; // get hours, minutes seconds
    Time &operator=(const Time &tt);
    friend Time operator+(const Time &lhs, const Time &rhs);
    friend Time operator-(const Time &lhs, const Time &rhs);
    friend bool operator<(const Time &lhs, const Time &rhs);
    friend bool operator>(const Time &lhs, const Time &rhs);
    friend bool operator<=(const Time &lhs, const Time &rhs);
    friend bool operator>=(const Time &lhs, const Time &rhs);
    friend bool operator==(const Time &lhs, const Time &rhs);
    friend bool operator!=(const Time &lhs, const Time &rhs);
};

Time operator+(const Time &lhs, const Time &rhs);
Time operator-(const Time &lhs, const Time &rhs);
bool operator<(const Time &lhs, const Time &rhs);
bool operator>(const Time &lhs, const Time &rhs);
bool operator<=(const Time &lhs, const Time &rhs);
bool operator>=(const Time &lhs, const Time &rhs);
bool operator==(const Time &lhs, const Time &rhs);
bool operator!=(const Time &lhs, const Time &rhs);

// Generic Departure
struct Depart
{
    Time ti; // time of departure
    Lndir dir; // direction of departure

    // Constructors
    Depart(Time = Time(0), Lndir dir_in = Lndir::fwd);
    Depart(const Depart &dep);
    // Assign
    Depart &operator=(const Depart &d);
};

// Driver structure
struct Driver
{
    string name;
    // Constructors
    Driver(string name_in = "");
    Driver(const Driver &drv);
    // Assign
    Driver &operator=(const Driver &drv);
    bool operator==(const Driver &drv) const;
    bool operator!=(const Driver &drv) const;
};

// list of drivers - std::list with ability to read from file.
struct DriverList : list<Driver>
{
    void loadFromFile(string filename);
};

// Timetable for one connection
struct PlanConn : public vector<Depart>
{
    Driver drv; // driver of the connection

    // Constructors
    PlanConn(Driver drv = Driver(), vector<Depart> d = vector<Depart>());
    PlanConn(const PlanConn &orig);

    //Assign
    PlanConn &operator=(const PlanConn &drv);
};

// Structure of a single line
struct Line
{
    vector<string> stops; // stops on the line in forward order
    vector<PlanConn> conns_fwd; // all connections of the line going forward
    vector<PlanConn> conns_bwd; // all connections of the line going backward

    Line() : stops({}), conns_fwd({}), conns_bwd({}){}; // Implicit constructor
    Line(const Line &orig);                             // Copy constructor
    Line & operator=(const Line &orig);                 // Copy-assignment
    // no destructor => implicit;
};

// structure of networks (Collection of lines)
class Network
{
protected:
    vector<Line> lines;
public:
    Line getLine(int ln) const; // returns line with number ln
    int nlines() const; // maximal number of lines
    Line operator()(int ln) const { return getLine(ln); } // Alias For getLine
    void loadFromFile(string filename); 
};


#endif