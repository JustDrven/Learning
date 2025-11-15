/*+++++++++++++++++++++++++++++++++++++++++++++++
 *
 *  Copyright (c) JustDrven, 2025
 * 
 * ++++++++++++++++++++++++++++++++++++++++++++++
 * 
 *  File: main.c
 *  Author: JustDrven (15-11-2025)
 *
 *  Description
 * +++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      This C file contains algorithm to manage
 *      many informations in one binary number
 * 
 *      This concept call "BIT PACKING"
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/


#include <stdio.h>


//
//  data type for 32 bits
//
typedef unsigned int                                  PRESULT;


//
//  Common utilities
//
int                                                   main();
#define LOG                                           printf

typedef unsigned char                                 BOOL;
#define TRUE                                          0b1
#define FALSE                                         0b0





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                                                                           //
//                          32 bits long binary number                       //
//                                                                           //
//              |===========================================|                //
//                                                                           //
//     +---------------+----------+----------------+-------------------+     //
//     |    6 bits     |   1 bit  |     10 bits    |     15 bits       |     //
//     +---------------+----------+----------------+-------------------+     //
//     |  Program      | Critical |    Facility    |       Code        |     //
//     +---------------+----------+----------------+-------------------+     //
//                                                                           //
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


//
//               Masks
//     |========================|
//

#define MASK_PROGRAM                                                0x3F
#define MASK_CRITICAL                                               0x1
#define MASK_FACILITY                                               0x3FF
#define MASK_CODE                                                   0x7FFF




//
//                Code
//     |========================|
//

#define CODE_NOTFOUND                                               404
#define CODE_OK                                                     200




//
//              Critical
//     |========================|
//

#define CRITICAL_OK                                                 ((BOOL) FALSE)
#define CRITICAL_FAILED                                             ((BOOL) TRUE)




//
//              Facility
//     |========================|
//

#define FACILITY_EXAMPLE                                            0x4



//
//              Program
//     |========================|
//

#define PROGRAM_EXAMPLE                                             0x1




//
//          PRESULT Utilities
//     |========================|
//

#define MAKEPRESULT(program, critical, facility, code)                                                                                                  \
    ((PRESULT) (((program & MASK_PROGRAM) << 26) | ((critical & MASK_CRITICAL) << 25) | ((facility & MASK_FACILITY) << 15) | (code & MASK_CODE)))       \

#define GET_PROGRAM(Result)                                         (( ((PRESULT) Result) >> 26) & MASK_PROGRAM)
#define GET_CRITICAL(Result)                                        (( ((PRESULT) Result) >> 25) & MASK_CRITICAL)
#define GET_FACILITY(Result)                                        (( ((PRESULT) Result) >> 15) & MASK_FACILITY)
#define GET_CODE(Result)                                            (( ((PRESULT) Result) & MASK_CODE))







int main() {

    const PRESULT result = MAKEPRESULT(
        PROGRAM_EXAMPLE, 
        
        CRITICAL_FAILED, 
        FACILITY_EXAMPLE, 

        CODE_NOTFOUND
    );


    LOG("\n");

    if (TRUE == GET_CRITICAL(result))
        LOG("This result is critical\n");



    LOG("\n");

    LOG("PROGRAM: %d\n", GET_PROGRAM(result));
    LOG("CRITICAL: %d\n", GET_CRITICAL(result));
    LOG("FACILITY: %d\n", GET_FACILITY(result));
    LOG("CODE: %d\n", GET_CODE(result));

    LOG("\n");
    
    return 0;
}
