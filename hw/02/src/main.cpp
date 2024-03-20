#include "MHD/doprava.hpp"
#include "MHD/solution.h"


using namespace std;

/*

int j_val = 0;
void print_table(Line linka, string stop, int line_number)
{
    int h, m ,s;
    std::cout << "+";
    for (int i = 0; i < 78; i++)
        {
            std::cout << "-" ;
        }
    std::cout << "+"<< std::endl;
    std::cout << "| "<< setw(38) << left << stop;
    std::cout << setw(37) << right << "Line: " << line_number << " |" << endl; 
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
    std::cout << "| "<< "To: "<< setw(33) << left << linka.stops.back() << " || To: " << setw(32) << left << linka.stops.front()<< "|" << endl;
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
    for (int i = 0; i < 24; i++)
    {
    
        if (i < 9 || i == 0)
        {
             linka.conns_fwd.at(i).at(j_val).ti.gett(h, m, s);
             
         
         std::cout << "| 0" << 00 + i << " |" << m << setw(38)<< right << " || 0" << 00 + i << " |"<< setw(33)<< right << "|" << endl;
         
        }
        if (i > 9)
        {
            
        std::cout << "| " << 00 + i << " |"<< setw(37)<< right << " || " << 00 + i << " |"<< setw(33)<< right << "|" << endl;
        }
        
       
    }
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

    for (int i = 0; i < linka.conns_fwd.size(); i++)
    {
       
        
             linka.conns_fwd.at(i).at(j_val).ti.gett(h, m, s); 
            std::cout << m <<" ";
        
        std::cout << endl;
    }
}

void print_timetable(Network net, string stop)
{
   
    for (int i = 0; i < net.nlines(); i++)
    {
       Line linka = net.getLine(i);
        for (int j = 0; j < linka.stops.size(); j++)
        {
            j_val = j;
            if (linka.stops.at(j) == stop)
            {
               
                print_table(linka, stop, i);
                break;


            }
        }
    }
   
}
*/

int main(int argc, char** argv) {

    // Load files:
    DriverList dl;
    dl.loadFromFile("driver_list.txt");

    Network net;
    net.loadFromFile("network.txt");

    NetworkInterface networkInterface(std::move(net));

    // variables for argument decoding
    std::string flag_in;
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
        for_each(stop_in.begin(), stop_in.end(), [&] (string stop_name) {networkInterface.print_timetable(stop_name);} );
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
