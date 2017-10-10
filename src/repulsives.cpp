// repulsives.cpp

/* ---------------------------------------------------------
   standard libraries
   --------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h> // strtod?, stod
// #include <assert.h>
// #include <string.h> // string.
// #include <cctype>
// #include <algorithm> // remove_if, count
#include <iostream>
// #include <fstream>
// #include <ctime>
// #include <list>        // std::list
// #include <vector>
// #include <iterator> // istream_iterator


/* ---------------------------------------------------------
   headers
   --------------------------------------------------------- */
#include "debug.h"
#include "repulsives.hpp"


/* ---------------------------------------------------------
   functions
   --------------------------------------------------------- */
// void ReadPDBfile (PDBfile *pdbfile,char filename[40],System sys)
SetRepulsives get_repulsively_interacting_indices(vAtoms aa,SetContacts lst_con)
{
    std::cout << "Getting repulsive interactions now." << std::endl;

    SetRepulsives lst_repulsives;
    int i,j;

    int num_natives = 0;
    // int i1,i2;
    int c1,c2;

    for(int i=0; i<aa.size(); i++)
    {
        // for(int j=0; j<aa.size(); j++)
        for(int j=i+2; j<aa.size(); j++)
        {
            if((j<=i+2) && (j>=i-2))
            {
                continue;
            }

            // Unless ...
            // if(i<j)
            // {
            //     i1 = i; // i1 is lower.
            //     i2 = j;
            // }
            // else
            // {
            //     i2 = i; // i1 is still lower.
            //     i1 = j;
            // }



            // std::cout << aa[i].index
            //           << " " << aa[i].chainid
            //           << "   " << aa[j].index
            //           << " " << aa[j].chainid
            //           << std::endl;

            for(auto c:lst_con)
            {
                c1 = c.get<0>();
                c2 = c.get<1>();

                // std::cout << c.get<0>()
                //     << " " << c.get<1>()
                //     << std::endl;

                // if((i1 == c1) && (i2 == c2))
                if((i == c1) && (j == c2))
                {
                    // std::cout << "This is a native interaction." << std::endl;
                    num_natives += 1;
                    break;
                }
                else
                {
                    lst_repulsives.push_back(boost::tuple<int,int>(c1,c2));
                }
            }
        }
    }

    std::cout << "The # of natives found: " << num_natives << std::endl;
    std::cout << "The # of non-native (repulsive) interactions is: "
              << lst_repulsives.size() << std::endl;


    return lst_repulsives;
}
