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
//
//                       32 bits long binary number
//
//           |===========================================|
//
//  +---------------+----------+----------------+-------------------+
//  |    6 bits     |   1 bit  |     10 bits    |     15 bits       |
//  +---------------+----------+----------------+-------------------+
//  |  Program      | Critical |    Facility    |       Code        |
//  +---------------+----------+----------------+-------------------+
//
//

#define MAKEPRESULT(program, critical, facility, code) ((PRESULT) (((program & 0x3F) << 26) | ((critical & 0x1) << 25) | ((facility & 0x3FF) << 15) | (code & 0x7FFF)))






int main() {

    PRESULT result = MAKEPRESULT(10, 1, 3, 22);

    printf("%d\n", (result & 0x7FFF));
    
    return 0;
}
