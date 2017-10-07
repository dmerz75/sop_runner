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

void read_bond_topology(std::string fn)
{
    // SetContacts contacts;
    SetBonds bonds;
    std::string line;
    std::string line_after1;
    std::string line_after2;
    // std::string fn(filename);

    std::string str_index1;
    std::string str_index2;
    std::string str_dist;
    std::string str_eh;

    int now_read;
    now_read = -1;

    int index1, index2;
    double dist, eh;
    index1 = index2 = -1;
    dist = eh = 0.0;

    std::cout << "Reading bonds from topology file: "
              << fn
              << std::endl;

    // std::ifstream cfile(fn.c_str());
    std::ifstream cfile(fn);

    std::size_t found1;
    std::size_t found2;

    // = str.find(str2);

    if(cfile.is_open())
    {
        std::cout << "file is now open." << std::endl;

        while(getline(cfile,line))
        {
            // SPACE LINE
            if(line.find_first_not_of(' ') == std::string::npos)
            {
                continue;
            }

            if(boost::algorithm::starts_with(line,"#") ||
               boost::algorithm::starts_with(line,";"))
            {
                continue;
            }

    //         // now_read += 1;
    //         // if(now_read != -1)
    //         // {
    //             // now_read += 1;

    //             // std::cout << now_read << ":";
    //             // std::cout << line << std::endl;

    //             found1 = line.find(" ");

    //             // Gets the line that starts/ends with a space.
    //             if (found1 == std::string::npos)
    //             {
    //                 std::cout << "lines corresponding to contacts: " << now_read << std::endl;
    //                 break;
    //             }

    //             // Index1:
    //             found1 = line.find_first_not_of(" ");
    //             found2 = line.find_first_not_of("0123456789",found1+1);
    //             str_index1 = line.substr(found1,found2);

    //             // Index2:
    //             line_after1 = line.substr(found2+1,std::string::npos);
    //             found1 = line_after1.find_first_not_of(" ");
    //             found2 = line_after1.find_first_not_of("0123456789",found1+1);
    //             str_index2 = line_after1.substr(found1,found2);

    //             // dist: (with a skip for that weird "1" in the topology)
    //             line_after2 = line_after1.substr(found2+1,std::string::npos);
    //             found1 = line_after2.find_first_not_of(" ");
    //             line_after2 = line_after2.substr(found1+1,std::string::npos);
    //             found1 = line_after2.find_first_not_of(" ");
    //             found2 = line_after2.find_first_not_of("0123456789.",found1+1);
    //             str_dist = line_after2.substr(found1,found2);

    //             // eh:
    //             str_eh = line_after2.substr(found2+1,std::string::npos);

    //             // std::cout << found1 << " " << found2 << std::endl;
    //             // std::cout << line_after1 << std::endl;

    //             // if(now_read > 500)
    //             // {
    //             //     break;
    //             // }


    //             // // ---------------FORMER ----------
    //             // str_index1 = line.substr(1,6);
    //             // str_index2 = line.substr(9,6);
    //             // str_dist = line.substr(22,9);
    //             // str_eh = line.substr(34,8);

    //             // // std::cout << str_index1 << " "
    //             // //           << str_index2 << " "
    //             // //           << str_dist << " "
    //             // //           << str_eh << "\n"
    //             // //           << std::endl;
    //             // // ---------------FORMER ----------



    //             index1 = atoi(str_index1.c_str());
    //             index2 = atoi(str_index2.c_str());
    //             dist = std::stod(str_dist.c_str());
    //             eh = std::stod(str_eh.c_str());


    //             // std::cout << index1 << " "
    //             //           << index2 << " "
    //             //           << dist << " "
    //             //           << eh << "\n"
    //             //           << std::endl;

    //             // contacts.push_back(boost::tuple<int,int,double,int,int,double>(
    //             //                        index1,
    //             //                        index2,
    //             //                        dist,
    //             //                        -1,
    //             //                        -1,
    //             //                        eh));
        // }
        }
        cfile.close();
    }
    std::cout << "file is now closed." << std::endl;
    std::cout << "# of bonds from topology file:  "
              << bonds.size() << std::endl;

    // // return contacts;
}
