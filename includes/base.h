/*+++++++++++++++++++++++++++++++++++++++++++++++
 *
 *  Copyright (c) JustDrven, 2025
 * 
 * ++++++++++++++++++++++++++++++++++++++++++++++
 * 
 *  File: base.h
 *  Author: JustDrven (16-11-2025)
 *
 *  Description
 * +++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      This header file is most important 
 *      file for manage application and
 *      modules
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef BASE_H
#define BASE_H



//
//  base annotation
//

#define INTERFACE           typedef struct
#define BIN(x)              0b##x

#define IN
#define OUT
#define API




//
//  assembly data types
//

typedef const               CONST;

typedef unsigned char       BYTE;
typedef signed char         SBYTE;

typedef unsigned short      WORD;
typedef signed short        SWORD;

typedef unsigned int        DWORD;
typedef signed int          SDWORD;

typedef unsigned long long  QWORD;
typedef long long           SQWORD;


typedef WORD                ATOM;
typedef char                CHAR, * PCHAR;



//
//  macroes
//

#define MAKECHAR(Value)     ((CHAR)(Value))
#define MAKEPCHAR(Value)    ((PCHAR)(Value))

#define MAKEWORD(Value)     (((DWORD) Value) & 0xFFFF)
#define MAKEDWORD(Value)    (((DWORD) Value) & 0xFFFFFFFF)
#define MAKEBYTE(Value)     (((BYTE) Value) & 0xFF)
#define MAKEATOM(Value)     (((ATOM) Value) & 0xFFFF)

//
//  integers data types
//

typedef long                LONG;
typedef unsigned long       ULONG;
typedef signed long         SLONG;



//
//  booleans
//

typedef CHAR                BOOL;
#define TRUE                0b1
#define FALSE               0b0



//
//  strings
//




#ifdef UNICODE
#define TEXT(x)             L##x
#else
#define TEXT(x)             x
#endif


INTERFACE {

    PCHAR Buffer;
    ULONG Length;

} BString;




//
//  handlers
//

typedef void *              HANDLE;

#ifdef NULL

#undef NULL
#define NULL                ((void*)0)

#endif













#endif
