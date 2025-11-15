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
 *      This C file contains macroes to
 *      manage bytes in array
 *      
 +++++++++++++++++++++++++++++++++++++++++++++++*/


#include <stdio.h>

typedef unsigned char   BYTE;
#define NEXTBYTE(p)     *(p)++
#define LOG(s, ...)     printf(s, __VA_ARGS__)

int main() {
    BYTE bytes[] = {1, 13, 2};
    BYTE* ptr = bytes;

    LOG("%d\n", *ptr);
    NEXTBYTE(ptr);
    LOG("%d\n", *ptr);

    NEXTBYTE(ptr);
    LOG("%d\n", *ptr);

    return 0;
}
