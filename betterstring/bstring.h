/*+++++++++++++++++++++++++++++++++++++++++++++++
 *
 *  Copyright (c) JustDrven, 2025
 * 
 * ++++++++++++++++++++++++++++++++++++++++++++++
 * 
 *  File: bstring.h
 *  Author: JustDrven (15-11-2025)
 *
 *  Description
 * +++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      This header file contains prototypes
 *      and struct to manage string
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/


//
//  I know, that can I use #pragma, but I think
//  this is more safer than #pragma once
//

#ifndef BSTRING_H
#define BSTRING_H


//
//  Data types
//

#define IN
#define OUT

#ifdef NULL

#undef NULL
#define NULL                ((void*) 0)

#endif



typedef unsigned long       size_t;
typedef char                CHAR, *PCHAR;


//
//  Structs
//

typedef struct {

    size_t Length;
    PCHAR Buffer;

} BString, *PBString;


//
//  Prototypes
//

IN BString 
InitBString(
    OUT PCHAR
);

IN size_t 
GetLength(
    IN PCHAR
);

void 
FreeBString(
    OUT PBString*
);



#endif

