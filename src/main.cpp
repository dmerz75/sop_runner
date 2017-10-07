// main.c

// standard libraries:
// #include <new>
#include <iostream>
#include <fstream>
// #include <stdio.h> // printf
/* #include <stdlib.h> */

// myheaders:
#include "debug.h"
#include "dcd.h"
#include "ReadPDBfile.hpp"
#include "contacts.hpp"
#include "parameters.hpp"
#include "global.hpp"
#include "bonds.hpp"

int main(int argc, char *argv[]) {


    // Modify Parameters:
    std::cout << "Default params: " << std::endl;
    params.print_parameters();
    read_sop_config(argv[1]);
    params.print_parameters();


    // Read Atoms from PDB, count # of atoms.
    vAtoms allatoms_ref;
    int num_atoms;
    // allatoms_ref = ReadPDBfile(argv[1]);
    allatoms_ref = ReadPDBfile(params.pdb);
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
    // lst_contacts = read_contacts_from_file(argv[2]);
    lst_contacts = read_contacts_from_file(params.topology);



    // Have:
    // atoms, starting coordinates, number of them.
    // topological interactions.

    // need bonds.
    // lst_bonds = read_bonds_topology(params.bonds_topology);
    read_bond_topology(params.bond_topology);





#ifdef DCDREAD
    /* ---------------------------------------------------------
       Step 3.0 DCD Read. Preload.
       --------------------------------------------------------- */
    int frame_position;
    frame_position = 0;
    int start,stop,step;

    // start,stop,step
    // start = atoi(argv[3]);
    // stop = atoi(argv[4]);
    // step = atoi(argv[5]);

    // start,stop,step
    start = 3;
    stop = 4;
    step = 5;


    /* ---------------------------------------------------------
       DCD Write. Preload.
       --------------------------------------------------------- */
#ifdef DCD_WRITE_B
    // std::string str_dcd_read(argv[2]);
    // std::size_t found;
    // found=str_dcd_read.find(".dcd",0);
    // std::string str_dcd_name = str_dcd_read.substr(0,found);
    // std::string str_dcd_write = str_dcd_name + "_subset.dcd";
    // char *fn_dcd_write = (char*) str_dcd_write.c_str();


    char *fn_dcd_write = (char*) params.dcdfile.c_str();


    // printf("\nreading dcd >>>  <%s>\n",str_dcd_read.c_str());
    // printf("using name for dcd >>>  <%s>\n",str_dcd_name.c_str());
    printf("writing dcd >>>  <%s>\n",fn_dcd_write);

    try
    {
        std::ofstream dcdfilewrite;
        dcdfilewrite.open(fn_dcd_write);
        // dcdfilewrite << "Writing this to a file.\n";
        dcdfilewrite.close();
    }
    catch (int param) { std::cout << "int exception"; }
    catch (char param) { std::cout << "char exception"; }
    catch (...) { std::cout << "default exception"; }

    // try
    // {
    //     std::ofstream dcdwritefile;
    //     dcdwritefile.open(fn_dcd_write);
    //     dcdwritefile.close();
    // }
    // exit(0);

    // Write DCD
    molfile_timestep_t timestep_w;
    void *vw;
    dcdhandle *dcdw;
    int natoms_w = 0;
    dcdw = (dcdhandle *)vw;

    // // get atom total for writing.
    // for(int i=0; i<num_chains; i++){
    //     natoms_w += chain_ref[i].num_atoms_ca;
    // }
    // printf("for dcd writing >>>  <%d> atoms expected.\n",natoms_w);
    printf("for dcd writing >>>  <%d> atoms expected.\n",num_atoms);


    // vw = open_dcd_write(fn_dcd_write,"dcd",natoms_w);
    vw = open_dcd_write(fn_dcd_write,"dcd",num_atoms);
    if (!vw) {
        fprintf(stderr, "main) open_dcd_write failed for file %s\n", *fn_dcd_write);
        return 1;
    } else {
        printf("opened <%s> successfully!!\n\n",fn_dcd_write);
    }

    // timestep_w.coords = (float *)malloc(3*sizeof(float)*natoms_w);
    timestep_w.coords = (float *)malloc(3*sizeof(float)*num_atoms);

    // dcd = (dcdhandle *)v;
    // sizeMB = ((natoms * 3.0) * dcd->nsets * 4.0) / (1024.0 * 1024.0);
    // totalMB += sizeMB;
    // printf("main) file: %s\n", *argv);
    // printf("  %d atoms, %d frames, size: %6.1fMB\n", natoms, dcd->nsets, sizeMB);
    // timestep.coords = (float *)malloc(3*sizeof(float)*natoms);
#endif // DCD_WRITE_B



    //     /* ---------------------------------------------------------
    //        Step 3.4 Advance DCD.
    //        --------------------------------------------------------- */
    //     // Advancing Rules.
    //     // ----------------
    //     // example. step size -> 5.
    //     // int advance_size = atoi(argv[3]) - 1;
    //     int advance_size = step - 1; // 0 counts, so advance_size of 4, advances by 5.

    //     // stop. Check that the stopping frame isn't beyond the actual frame count.
    //     if(stop > dcd->nsets)
    //     {
    //         stop = dcd->nsets;
    //         std::cout << "Use stop value: " << stop << std::endl;
    //     }


    //     /* ---------------------------------------------------------
    //        Step 3.5 Fast Forward DCD
    //        --------------------------------------------------------- */
    //     for (int nset1=2; nset1<start; nset1 += 1 )
    //     {
    //         frame_position += advance_dcd(dcd->nsets,0,dcd,natoms,&timestep);
    //         allatoms = load_dcd_to_atoms(dcd,allatoms);
    //         debug("forwarding --> frame_position: %d\n",frame_position);
    //     }

    //     // Get initial starting point.
    //     printf("FF: -->\nframe_position: %d\n",frame_position);


    //     /* ---------------------------------------------------------
    //        Step 3.6 Loop through DCD, evaluate. (do loop)
    //        --------------------------------------------------------- */
    //     int nset2;
    //     nset2 = frame_position;
    //     do {
#endif //DCDREAD



#ifdef DCD_WRITE
    /* ---------------------------------------------------------
       Step 3. DCD Write. Finish.
       --------------------------------------------------------- */
    // READ
    // static void *open_dcd_read(const char *path, const char *filetype,
    //                            int *natoms) {
    // int rc = read_next_timestep(v, natoms, timestep);

    // WRITE
    // static void *open_dcd_write(const char *path, const char *filetype,
    //                             int natoms) {
    // static void close_file_write(void *v) {

    // open_dcd_write(fn_dcd_write,"dcd",&natoms);

    // write_dcdstep
    // static int write_dcdstep(fio_fd fd, int curframe, int curstep, int N,
    //                          const float *X, const float *Y, const float *Z,
    //                          const double *unitcell, int charmm) {

    // static int write_dcdheader(fio_fd fd, const char *remarks, int N,
    //                            int ISTART, int NSAVC, double DELTA, int with_unitcell,
    //                            int charmm) {

    // load_chain_coords_to_timestep(dcdw,chain_later,chains_to_use,vw,&timestep_w,natoms_w);
    // load_chain_coords_to_timestep(chain_later,num_chains,&timestep_w);

    // THIS ONE
    // load_chain_to_timestep(chain_later,num_chains,&timestep_w);
    // load_atom_to_timestep(&timestep_w,aa_later);
    // load_atom_to_timestep(&timestep_w,*allatoms);


    // WRITE HERE NEXT!

    // The Primary Loop!

    // load_atom_to_timestep(&timestep_w,*allatoms);


#ifdef DCD_WRITE_UNMOD
    // Write the DCD read in.
    write_timestep(vw,&timestep);
#else
    // Write modified coordinates.
    write_timestep(vw,&timestep_w);
#endif // DCD_WRITE_UNMOD


#endif // DCD_WRITE



    // #ifdef DCDREAD
    //         /* ---------------------------------------------------------
    //            Step 3.6 DCD READ
    //            --------------------------------------------------------- */
    //         debug("current: %d\n",nset2);
    //         printf("frame: --> %d <-- was evaluated.\n",frame_position);

    //         if (nset2 + advance_size + 1 <= stop)
    //         {
    //             frame_position += advance_dcd(dcd->nsets,advance_size,dcd,natoms,&timestep);
    //             printf("frame: --> %d <-- loaded.\n",frame_position);

    //             // THIS ONE
    //             allatoms = load_dcd_to_atoms(dcd,allatoms);
    //         }
    //         nset2 += advance_size + 1;
    //     } while (nset2<=stop);

    //     debug("\n..closing dcd..\n");
    //     close_file_read(v);

    //     printf("\n----->  READING DCD completed!  <-----\n");
    //     printf("\t\tThe maximum possible frame_position was: %d\n",stop);
    //     printf("\t\tThe last frame evaluated was: %d\n",frame_position);
    // #endif //DCDREAD END



#ifdef DCD_WRITE_E
    // open_dcd_write(fn_dcd_write,"dcd",natoms);
    // static void close_file_write(void *v) {
    close_file_write(vw);
#endif // DCD_WRITE_E

    // #endif // multi-if

    // Bonds/FENE
    // Noncovalents-bonded (attractive)
    // Noncovalents-not-bonded (repulsive)


    /* ---------------------------------------------------------
       The End.
       --------------------------------------------------------- */
    std::cout << "\nClosing stdin,stdout,stderr.." << std::endl;
    std::cout << "Sop_Runner Complete!" << std::endl;
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    return 0;
}
