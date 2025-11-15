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
 *      This C file contains funcs & macroes
 *      to manage IP
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>


//
//  IP macro
//

typedef unsigned long long int      IP;

#define IP_MASK                     255
#define MAKEIPV4(p0, p1, p2, p3)    ((((IP) p0) & IP_MASK) << 50)     |       \
                                    ((((IP) p1) & IP_MASK) << 40)     |       \
                                    ((((IP) p2) & IP_MASK) << 30)     |       \
                                    ((((IP) p3)) & IP_MASK)                   \

//
//  Utilities
//

int main();
void printIP(IP);





int main() {

    //
    //  Generate 64 bits IP
    //
    IP ip = MAKEIPV4(
        34,
        21,
        2,
        0
    );

    printIP(ip);

    return 0;
}

void printIP(IP ip) {

    IP p0 = (ip >> 50) & IP_MASK;
    IP p1 = (ip >> 40) & IP_MASK;
    IP p2 = (ip >> 30) & IP_MASK;
    IP p3 = ip & IP_MASK;

    printf("IP: %llu.%llu.%llu.%llu\n", p0, p1, p2, p3);

}


