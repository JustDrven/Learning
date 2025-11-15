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
 *      This C file contains test section for
 *      bstring (Better String)
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include "bstring.h"


int main() {
    PCHAR buffer = "Hello from Better String Buffer";

    BString bstring = InitBString(
        buffer
    );


    printf("Buffer: %s\n", bstring.Buffer);
    printf("Length: %zu\n", bstring.Length);
    
    
    return 0;
}
