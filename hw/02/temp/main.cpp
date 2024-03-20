#include <iostream>
#include <vector>
#include "doprava.hpp"

//Feel free to create your solution in multiple files
// and add the includes here. e.g.:
//#include "solution.hpp"

using namespace std;

int main(int argc, char** argv) {

    // Load files:
    DriverList dl;
    dl.loadFromFile("driver_list.txt");

    Network net;
    net.loadFromFile("network.txt");

    // variables for argument decoding
    string flag_in;
    list<string> stop_in;

    if (argc > 1)
        flag_in = string(argv[1]);
    else
    {
        cerr << "Missing argument. Terminating." << endl;
        return 1;
    }

    if ((!flag_in.compare("--schedule")))
    {
        // input check - do not edit
        if (argc > 2)
        {
            for (int i = 2; i < argc; i++)
            {
                string temp = argv[i];
                replace(temp.begin(), temp.end(), '_', ' ');
                stop_in.push_back(temp);
            }
        }
        else
        {
            cerr << "Missing stop name. Terminating." << endl;
            return 2;
        }
        // end of input check

        /* here should start the code for printing timetables*/
        /* stop_in contains names of stops, for which the timetable is to be printed. */
        
        // This is an example, how it can be done using lambda-function
        for_each(stop_in.begin(), stop_in.end(), [&] (string stop_name) {print_timetable(net,stop_name);} );
        // This is an example, how it can be done using for-loop 
        // for( auto iter = stop_in.begin(); iter != stop_in.end(); iter++) print_timetable(net,*iter);

        /* here should end the code for printing timetables*/
    }
    else if ((!flag_in.compare("--line-routing")))
    {

        /* here should start the code for printing line routes without stats*/



        /* here should end the code for printing line routes without stats*/
    }
    else if ((!flag_in.compare("--driver-stops")))
    {

        /* here should start the code for stops statistics for drivers */



        /* here should end the code for stops statistics for drivers */
    }
    else
    {
        cout << "Flag not recognized, terminating." << endl;
    }
    
    return 0;
}