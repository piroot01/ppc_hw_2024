#include "doprava.hpp"
using namespace std;

Time::Time(int ss) : seconds(ss) {} // initialize by seconds after midnight: seconds(ss){};

Time::Time(int hh, int mm, int ss) : seconds(3600 * hh + 60 * mm + ss) {} // initialize by hours, minutes seconds

Time::Time(const Time &tt) : seconds(tt.seconds) {} // copy-constructor

Time &Time::operator=(const Time &tt)
{
    this->seconds = tt.seconds;
    return *this;
}

int Time::gets() const { return seconds; }       // get seconds after midnight // {return ss;}
void Time::gett(int &hh, int &mm, int &ss) const // get hours, minutes, seconds
{
    ss = seconds;
    hh = ss / 3600;
    ss -= 3600 * hh;
    mm = ss / 60;
    ss -= 60 * mm;
}

Time operator+(const Time &lhs, const Time &rhs) { return Time(lhs.seconds + rhs.seconds); }
Time operator-(const Time &lhs, const Time &rhs) { return Time(lhs.seconds - rhs.seconds); }
bool operator<(const Time &lhs, const Time &rhs) { return lhs.seconds < rhs.seconds; }
bool operator>(const Time &lhs, const Time &rhs) { return rhs < lhs; }
bool operator<=(const Time &lhs, const Time &rhs) { return !(lhs > rhs); }
bool operator>=(const Time &lhs, const Time &rhs) { return !(lhs < rhs); }
bool operator==(const Time &lhs, const Time &rhs) { return lhs.seconds == rhs.seconds; }
bool operator!=(const Time &lhs, const Time &rhs) { return !(lhs == rhs); }

Depart::Depart(Time ti_in, Lndir dir_in) : ti(ti_in), dir(dir_in) {}

Depart::Depart(const Depart &dep) : Depart(dep.ti, dep.dir) {}

Depart &Depart::operator=(const Depart &d)
{
    this->ti = d.ti;
    this->dir = d.dir;
    return *this;
}

PlanConn::PlanConn(Driver drv_in, vector<Depart> d) : vector<Depart>(d), drv(drv_in) {}
PlanConn::PlanConn(const PlanConn &orig) : PlanConn(orig.drv, orig) {}
PlanConn &PlanConn::operator=(const PlanConn &orig)
{
    if (&orig != this) // if not identical
    {
        this->drv = orig.drv;
        this->clear();
        for (auto it = orig.begin(); it != orig.end(); it++)
            this->push_back(*it);
    }
    return *this;
}

Driver::Driver(string name_in) : name(name_in) {}

Driver::Driver(const Driver &drv) : name(drv.name) {}

Driver &Driver::operator=(const Driver &drv)
{
    this->name = drv.name;
    return *this;
}

bool Driver::operator==(const Driver &drv) const
{
    return !name.compare(drv.name);
}

bool Driver::operator!=(const Driver &drv) const
{
    return name.compare(drv.name);
}

void DriverList::loadFromFile(string filename)
{
    string tmpstr;
    int drivercount;
    ifstream infile(filename);
    if (infile.is_open())
    {
        for (drivercount = 0; getline(infile, tmpstr); drivercount++)
            this->push_back(Driver(tmpstr));
        cout << "Loaded " << drivercount << " names from " << filename << ".\n";
        infile.close();
    }
    else
    {
        cout << "Could not open " << filename << ". Driver List not loaded." << endl;
    }
}

Line::Line(const Line &orig) : stops(orig.stops), conns_fwd(orig.conns_fwd), conns_bwd(orig.conns_bwd) {}

Line &Line::operator=(const Line &orig)
{
    this->stops = orig.stops;
    this->conns_fwd = orig.conns_fwd;
    this->conns_bwd = orig.conns_bwd;
    return *this;
}

Line Network::getLine(int ln) const
{
    if (ln < 0 || (unsigned)ln >= this->lines.size())
        throw out_of_range("Line number out of range.");
    else
        return lines[ln];
}

int Network::nlines() const
{
    return this->lines.size();
}

void Network::loadFromFile(string filename)
{

    Line tmpL;
    Depart tmpD;
    PlanConn tmpC;
    Lndir tmpdir;

    string tmpstr;

    ifstream infile(filename);
    if (infile.is_open())
    {
        while (getline(infile, tmpstr))
        {
            if (tmpstr.rfind("{", 0) == 0) //if dbegin with "{", create new line
            {
                tmpC.clear();
                istringstream ss(tmpstr);
                char ch;
                int sec;

                string token;
                ss >> ch;
                if (ch != '{' || !ss.good())
                {
                    infile.close();
                    throw file_corrupt();
                }
                ss >> ch;
                if (ch == 'f' && ss.good())
                    tmpdir = Lndir::fwd;
                else if (ch == 'b' && ss.good())
                    tmpdir = Lndir::bwd;
                else
                    throw file_corrupt();
                ss >> ch;
                if (ch != ';' || !ss.good())
                {
                    infile.close();
                    throw file_corrupt();
                }

                if (!getline(ss, token, ';'))
                {
                    infile.close();
                    throw file_corrupt();
                }
                tmpC.drv = Driver(token);

                ch = ';';
                while (ch == ';')
                {
                    ss >> sec;
                    ss >> ch;
                    if (!ss.good())
                        throw file_corrupt();
                    tmpC.push_back(Depart(Time(sec), tmpdir));
                }
                if (ch == '}')
                    if (tmpdir == Lndir::fwd)
                        tmpL.conns_fwd.push_back(tmpC);
                    else
                        tmpL.conns_bwd.push_back(tmpC);
                else
                {
                    infile.close();
                    throw file_corrupt();
                }
            }
            else if (tmpstr.rfind("#####", 0) == 0) //if begins with "#####", push_back line
            {
                this->lines.push_back(tmpL);
            }
            else // we have to start a new line!
            {
                tmpL.stops.clear();
                tmpL.conns_fwd.clear();
                tmpL.conns_bwd.clear();
                istringstream ss(tmpstr);
                string token;
                while (getline(ss, token, ';'))
                {
                    // cout<< token<< endl;
                    tmpL.stops.push_back(token);
                }
            }
        }

        infile.close();
        std::cout << "Loaded network from " << filename << ".\n";
    }
    else
    {
        std::cout << "Could not open " << filename << ". Network not loaded." << endl;
    }
}

