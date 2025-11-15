/*+++++++++++++++++++++++++++++++++++++++++++++++
 *
 *  Copyright (c) JustDrven, 2025
 * 
 * ++++++++++++++++++++++++++++++++++++++++++++++
 * 
 *  File: bstring.c
 *  Author: JustDrven (15-11-2025)
 *
 *  Description
 * +++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      This C file contains implemention
 *      of bstring (Better String) header
 *      file
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdlib.h>
#include "bstring.h"


IN BString InitBString(OUT PCHAR buff) {

    BString bstring;

    bstring.Buffer = buff;
    bstring.Length = GetLength(buff);


    return bstring;
}


IN size_t GetLength(IN PCHAR buff) {
    CHAR currentChar;
    size_t size = 0;

    do {

        size++;

        currentChar = buff[size];

    } while (currentChar != '\0');

    return size;
}


void FreeBString(OUT PBString* ptrbstring) {
    PBString bstring = *ptrbstring;

    free(bstring->Buffer);
    free(bstring);
    bstring = NULL;
}
