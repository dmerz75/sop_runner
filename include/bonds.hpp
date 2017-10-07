# // 1: c++, c: bonds
# // 2: name:
# // .bonds
#ifndef BONDS_H
#define BONDS_H

/* ---------------------------------------------------------
   libraries:
   --------------------------------------------------------- */
// #include <stdio.h>
// #include <stdlib.h> // strtod?, stod
// #include <assert.h>
#include <string.h> // string
// #include <cctype.h>
/* #include <algorithm> // remove_if, count */
/* #include <iostream> */
/* #include <fstream> */
/* #include <ctime> */
// #include <list>        // std::list
#include <vector>
// #include <iterator> // istream_iterator
#include "boost/tuple/tuple.hpp"



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

typedef boost::tuple<int,int,double> Bond;
typedef std::vector<Bond> SetBonds;



/* ---------------------------------------------------------
   Classes:
   --------------------------------------------------------- */
// header_class



/* ---------------------------------------------------------
   function declarations:
   --------------------------------------------------------- */
// void ReadPDBfile(PDBfile *pdbfile,char filename[40]);
void read_bond_topology(std::string fn_bonds);

#endif
