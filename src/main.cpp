// main.c

// standard libraries:
// #include <new>
#include <iostream>
// #include <stdio.h> // printf
/* #include <stdlib.h> */

// myheaders:
#include "debug.h"
#include "dcd.h"
#include "ReadPDBfile.hpp"
#include "contacts.hpp"
#include "parameters.hpp"


// Global Parameters:
Parameters params;


int main(int argc, char *argv[]) {


    // Read Atoms from PDB, count # of atoms.
    vAtoms allatoms_ref;
    int num_atoms;
    allatoms_ref = ReadPDBfile(argv[1]);
    num_atoms = allatoms_ref.size();
    //
    std::cout << "Number of atoms in allatoms_ref: " << allatoms_ref.size() << std::endl;

    // Reserve space for the standards.
    // allatoms_ref  -->  allatoms_0, allatoms.
    vAtoms allatoms_0; // from DCD-0
    vAtoms allatoms; // evolve in time.
    allatoms_0.reserve(num_atoms);
    allatoms.reserve(num_atoms);

    // Set the chainid based on switch from chain A to chain B .. etc.
    allatoms_ref = set_chainid(allatoms_ref);


    // Identify the nucleotide.
    IndexGroup chainD;
    chainD = select(allatoms_ref,"chain D");
    std::cout << "chain D: " << chainD.size() << std::endl;


    // Read topology.
    SetContacts lst_contacts;
    lst_contacts = read_contacts_from_file(argv[2]);


    // Modify Parameters:
    std::cout << "Default params: " << std::endl;
    std::cout << params.size << " "
              << params.x << " "
              << params.y << " "
              << params.z << " "
              << std::endl;




    return 0;
}
