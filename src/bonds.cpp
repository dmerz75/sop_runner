// bonds.cpp

/* ---------------------------------------------------------
   standard libraries
   --------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h> // strtod?, stod
// #include <assert.h>
#include <string> // string.
// #include <cctype>
// #include <algorithm> // remove_if, count
#include <iostream>
#include <fstream>
// #include <ctime>
// #include <list>        // std::list
// #include <vector>
// #include <iterator> // istream_iterator
#include "boost/tuple/tuple.hpp"
#include <boost/algorithm/string.hpp>


/* ---------------------------------------------------------
   headers
   --------------------------------------------------------- */
#include "debug.h"
#include "bonds.hpp"


/* ---------------------------------------------------------
   functions
   --------------------------------------------------------- */
// void ReadPDBfile (PDBfile *pdbfile,char filename[40],System sys)

SetBonds read_bond_topology(std::string fn)
{
    // SetContacts contacts;
    SetBonds bonds;
    std::string line;
    std::string line_after1;
    std::string line_after2;


    std::size_t found1;
    std::size_t found2;

    int index1, index2;
    double dist, eh;
    index1 = index2 = -1;
    dist = eh = 0.0;

    std::ifstream bondfile(fn);

    if(bondfile.is_open())
    {
        std::cout << "Opening/reading bonds from topology file: "
                  << fn
                  << std::endl;
        // std::cout << "file is now open." << std::endl;

        while(getline(bondfile,line))
        {
            // // SPACE LINE
            // if(line.find_first_not_of(' ') == std::string::npos)
            // {
            //     continue;
            // }

            if(boost::algorithm::starts_with(line,"#") ||
               boost::algorithm::starts_with(line,";"))
            {
                continue;
            }

            // std::cout << line << std::endl;

            // Index1:
            found1 = line.find_first_not_of(" ");
            found2 = line.find_first_not_of("0123456789",found1+1);
            index1 = std::stoi(line.substr(found1,found2));

            // Index2:
            line_after1 = line.substr(found2+1,std::string::npos);
            found1 = line_after1.find_first_not_of(" ");
            found2 = line_after1.find_first_not_of("0123456789",found1+1);
            index2 = std::stoi(line_after1.substr(found1,found2));


            // Distance:
            line_after2 = line_after1.substr(found2+1,std::string::npos);
            found1 = line_after2.find_first_not_of(" ");
            found2 = line_after2.find_first_not_of("0123456789.",found1+1);
            dist = std::stod(line_after2.substr(found1,found2));

            // Bond:
            bonds.push_back(boost::tuple<int,int,double>
                            (index1,index2,dist));

            // PRINT HERE:
            // std::cout << "the bond indices are: "
            //           << index1 << "   " << index2
            //           << " dist: " << dist
            //           << std::endl;
        }
        bondfile.close();
        std::cout << "file is now closed." << std::endl;
        std::cout << "# of bonds from topology file:  "
                  << bonds.size() << std::endl;
    } // ^^^ only if opened.
    else
    {
        std::cout << "Unable to open the bond topology." << std::endl;
        exit(1);
    }

    return bonds;
}
