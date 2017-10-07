//File: parameters.hpp
#ifndef PARAMETERS_H
#define PARAMETERS_H

/* ---------------------------------------------------------
   libraries:
   --------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h> // strtod?, stod
// #include <assert.h>
// #include <string.h> // string
// #include <cctype.h>
/* #include <algorithm> // remove_if, count */
#include <iostream>
/* #include <fstream> */
/* #include <ctime> */
// #include <list>        // std::list
/* #include <vector> */
// #include <iterator> // istream_iterator



/* ---------------------------------------------------------
   headers:
   --------------------------------------------------------- */
#include "debug.h"
// #include "bonds.hpp"
/* #include "system.hpp" */
// #include "atom.hpp"



/* ---------------------------------------------------------
   Definitions:
   --------------------------------------------------------- */
/* #define BUFFERSIZE 900 */


/* ---------------------------------------------------------
   Classes:
   --------------------------------------------------------- */

class Parameters
{
private:
    char *s;
    // int size;
public:

    Parameters(); // constructor
    ~Parameters();      // destructor
    void print_parameters();

    int size;
    double x,y,z;
    int steps,dcdfreq,dcdstart; // total steps, dcdfreq, dcdstart;
    std::string pdb = "mol1.pdb";
    std::string topology = "emol.top";
    std::string dcdfile = "mol1.dcd";
    std::string bond_topology = "bond_topology.top";

};

inline Parameters::Parameters()
{
    size = 1;
    x = -0.0009;
    y = -0.0008;
    z = -0.0007;

    steps = 10000;
    dcdfreq = 10000;
    dcdstart = 0;

    // size = strlen(c);
    // s = new char[size+1];
    // strcpy(s,c);

}
inline Parameters::~Parameters()
{
    delete []s;
}
inline void Parameters::print_parameters()
{
    std::cout << "---*--- Configuration ---*---" << std::endl;
    std::cout << "pdb: " << pdb << std::endl;
    std::cout << "dcd: " << dcdfile << std::endl;
    std::cout << "topology: " << topology << std::endl;
    std::cout << "bond_topology: " << bond_topology << std::endl;

    std::cout << "steps: " << steps << std::endl;
    std::cout << "dcdfreq: " << dcdfreq << std::endl;
    std::cout << "dcdstart: " << dcdstart << std::endl;

}


/* ---------------------------------------------------------
   function declarations:
   --------------------------------------------------------- */
// void ReadPDBfile(PDBfile *pdbfile,char filename[40]);
// void read_config_modify_parameters();
// void read_sop_config(char filename[40]);
void read_sop_config(std::string sopconfig);
// void print_config();

// Global Parameters:
// Parameters params;



#endif
