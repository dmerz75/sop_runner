# // 1: c++, c: repulsives
# // 2: name:
# // .repulsives
#ifndef REPULSIVES_H
#define REPULSIVES_H

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
// #include <iterator> // istream_iterator
// #include <string>
#include <vector>
#include "boost/tuple/tuple.hpp"


/* ---------------------------------------------------------
   headers:
   --------------------------------------------------------- */
#include "debug.h"
#include "bonds.hpp"
#include "contacts.hpp"
// #include "system.hpp"
// #include "atom.hpp"



/* ---------------------------------------------------------
   Definitions:
   --------------------------------------------------------- */
/* #define BUFFERSIZE 900 */
typedef boost::tuple<int,int> Repulsive;
typedef std::vector<Repulsive> SetRepulsives;


/* ---------------------------------------------------------
   Classes:
   --------------------------------------------------------- */
// header_class



/* ---------------------------------------------------------
   function declarations:
   --------------------------------------------------------- */
// void ReadPDBfile(PDBfile *pdbfile,char filename[40]);
SetRepulsives get_repulsively_interacting_indices(vAtoms aa, SetContacts lst_con);


#endif
