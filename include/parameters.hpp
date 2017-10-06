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
/* #include <iostream> */
/* #include <fstream> */
/* #include <ctime> */
// #include <list>        // std::list
/* #include <vector> */
// #include <iterator> // istream_iterator



/* ---------------------------------------------------------
   headers:
   --------------------------------------------------------- */
#include "debug.h"
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

    int size;
    double x,y,z;

    Parameters(); // constructor
    ~Parameters();      // destructor
};

inline Parameters::Parameters()
{
    size = 1;
    x = -0.0009;
    y = -0.0008;
    z = -0.0007;

    // size = strlen(c);
    // s = new char[size+1];
    // strcpy(s,c);

}
inline Parameters::~Parameters()
{
    delete []s;
}


/* ---------------------------------------------------------
   function declarations:
   --------------------------------------------------------- */
// void ReadPDBfile(PDBfile *pdbfile,char filename[40]);
// void read_config_modify_parameters();

#endif
