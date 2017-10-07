// parameters.cpp

/* ---------------------------------------------------------
   standard libraries
   --------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h> // strtod?, stod
// #include <assert.h>
#include <string.h> // string.
// #include <cctype>
// #include <algorithm> // remove_if, count
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
// #include <ctime>
// #include <list>        // std::list
#include <vector>
// #include <iterator> // istream_iterator


/* ---------------------------------------------------------
   headers
   --------------------------------------------------------- */
#include "debug.h"
#include "parameters.hpp"
#include "global.hpp"


// extern in header(that is included in many places), defined in a source file.
Parameters params;


/* ---------------------------------------------------------
   functions
   --------------------------------------------------------- */
// void ReadPDBfile (PDBfile *pdbfile,char filename[40],System sys)
// void read_sop_config()
void read_sop_config(std::string sopconfig)
{
    std::cout << "Reading sop config: " << std::endl;

    // std::ofstream myfile;
    // myfile.open("sop.conf");

    std::string line;
    std::vector<std::string> results;

    // std::ifstream myfile("sop.conf");
    std::ifstream myfile(sopconfig);

    if (myfile.is_open())
    {
        // myfile << "This is a line.\n";
        // myfile << "This is another line.\n";
        // myfile.close();

        while(getline(myfile,line))
        {
            // std::cout << line << '\n';

            // SPACE LINE
            if(line.find_first_not_of(' ') == std::string::npos)
            {
                continue;
            }

            if(boost::algorithm::starts_with(line,"#") ||
               boost::algorithm::starts_with(line,";"))
               // ||
               // boost::algorithm::starts_with(line,' '))
               // boost::algorithm::starts_with(line,"\n") ||
            {
                // std::cout << "continuing\n" << std::endl;
                continue;
            }


            // std::cout << line << std::endl;
            // << std::endl;


            // Now begins the IF parameters:

            if(boost::algorithm::starts_with(line,"steps"))
            {
                // std::cout << params.steps << std::endl;
                // std::cout << line << std::endl;
                // params.steps =
                boost::split(results, line, [](char c){return c ==' ';});

                // std::vector<int>::iterator iter;

                // std::cout << results.size() << std::endl;
                // std::cout << results[0] << std::endl;
                // std::cout << results[1] << std::endl;
                // std::cout << results[results.size()-1] << std::endl;
                params.steps = std::stoi(results[results.size()-1]);
                // exit(0);
            }

            if(boost::algorithm::starts_with(line,"dcdfreq"))
            {
                boost::split(results, line, [](char c){return c ==' ';});
                params.dcdfreq = std::stoi(results[results.size()-1]);
            }
            if(boost::algorithm::starts_with(line,"dcdstart"))
            {
                boost::split(results, line, [](char c){return c ==' ';});
                params.dcdstart = std::stoi(results[results.size()-1]);
            }
            if(boost::algorithm::starts_with(line,"pdb") ||
               boost::algorithm::starts_with(line,"coordinates"))
            {
                boost::split(results, line, [](char c){return c ==' ';});
                params.pdb = results[results.size()-1];
            }
            if(boost::algorithm::starts_with(line,"topology"))
            {
                boost::split(results, line, [](char c){return c ==' ';});
                params.topology = results[results.size()-1];
            }
            if(boost::algorithm::starts_with(line,"dcdfile"))
            {
                boost::split(results, line, [](char c){return c ==' ';});
                params.dcdfile = results[results.size()-1];
            }
            if(boost::algorithm::starts_with(line,"bond_topology"))
            {
                boost::split(results, line, [](char c){return c ==' ';});
                params.bond_topology = results[results.size()-1];
            }



        }

        myfile.close();
    } // closed already.
    else
    {
        std::cout << "Unable to open file";
    }


    // myfile.close();
    // return 0;
}

// void print_config()
// {
//     std::cout << "Configuration:" << std::endl;
// }
