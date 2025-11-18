/*+++++++++++++++++++++++++++++++++++++++++++++++
 *
 *  Copyright (c) JustDrven, 2025
 * 
 * ++++++++++++++++++++++++++++++++++++++++++++++
 * 
 *  File: main.c
 *  Author: JustDrven (18-11-2025)
 *
 *  Description
 * +++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      This file contains functions to
 *      handle flags
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/


//
//  includes
//
#include <stdio.h>


//
//  typedefs & macroes
//
typedef char                                            CHAR, *PCHAR;
typedef const PCHAR                                     CPCHAR;
typedef unsigned int                                    DWORD;
typedef char                                            BOOL;

#define TRUE                                            0x1
#define FALSE                                           0x0


//
//  utilities
//
#define LOG                                             printf
#define MAKERESORCE(Times)                              ((1) << (Times))   // this only shift left specific bit
#define MAKEDWORD(Value)                                (((DWORD) Value))  // this is unnecessary but, whatever



//------------------------------------------------
//
//  void ResetFlags(DWORD*);
//  
//  Description:
//
//    - This function just set value of pointer
//      to 0
//
//  Return Value:
//
//    - None
//
//------------------------------------------------
void ResetFlags(DWORD* Flags);







//------------------------------------------------
//
//  void SetFlags(DWORD*, DWORD);
//  
//  Description:
//
//    - This function create flags
//
//  Return Value:
//
//    - None
//
//------------------------------------------------
void SetFlag(DWORD* Flags, DWORD ToSet);





//------------------------------------------------
//
//  BOOL HasFlag(DWORD, DWORD);
//  
//  Description:
//
//    - This function check if 
//      specific bit is set
//
//  Return Value:
//
//    - If specific bite is set (1)
//      return TRUE, otherwise
//
//------------------------------------------------
BOOL HasFlag(DWORD Flags, DWORD ToCheck);






//------------------------------------------------
//
//  int main();
//  
//  Description:
//
//    - This function is start
//      entry point for C
//
//  Return Value:
//
//    - Status code if program
//      was success or not
//
//------------------------------------------------

int main();



//
//  flags
//

//
//  like example we use "game" flags for entities
//  as player
//

#define FLAG_PLAYER_ONLINE                              MAKERESORCE(0)
#define FLAG_PLAYER_ALIVE                               MAKERESORCE(1)
#define FLAG_PLAYER_BANNED                              MAKERESORCE(2)
#define FLAG_PLAYER_ADMIN                               MAKERESORCE(3)
#define FLAG_PLAYER_SPECIAL_MAGIC                       MAKERESORCE(4)



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                                                                           //
//                                I M P L E M E N T A T I O N                                //
//                                                                                           //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//



int main() {

    //
    //  properties
    //
    CPCHAR Space = "-------------";
    DWORD Flags;


    LOG("%s\n", Space);

    //
    //  set flags 
    //
    SetFlag(&Flags, (FLAG_PLAYER_ONLINE | FLAG_PLAYER_ADMIN | FLAG_PLAYER_ALIVE));
    

    LOG("Flags: %d\n", Flags);




    //
    //  this should be true
    //
    if (HasFlag(Flags, FLAG_PLAYER_ADMIN))
        LOG("True\n");
    else
        LOG("False\n");


    LOG("%s\n", Space);



    //
    //  this should be true
    //
    if (HasFlag(Flags, FLAG_PLAYER_ALIVE))
        LOG("True\n");
    else
        LOG("False\n");


    LOG("%s\n", Space);



    //
    //  this should be false
    //
    if (HasFlag(Flags, FLAG_PLAYER_BANNED))
        LOG("True\n");
    else
        LOG("False\n");


    LOG("%s\n", Space);




    //
    //  reset flags
    //

    ResetFlags(&Flags);



    //
    //  this should be false
    //
    if (HasFlag(Flags, FLAG_PLAYER_ADMIN))
        LOG("True\n");
    else
        LOG("False\n");




    //
    //  set flags again
    //
    SetFlag(&Flags, (FLAG_PLAYER_SPECIAL_MAGIC | FLAG_PLAYER_ALIVE));


    LOG("%s\n", Space);


    //
    //  this should be true
    //
    if (HasFlag(Flags, FLAG_PLAYER_ALIVE) && 
        HasFlag(Flags, FLAG_PLAYER_SPECIAL_MAGIC))

        LOG("True\n");

    else

        LOG("False\n");








    LOG("%s\n", Space);

    return 0;
}




//
//  helpers
//

void ResetFlags(DWORD* Flags) {
    *Flags = 0;
}

void SetFlag(DWORD* Flags, DWORD ToSet) {
    if (*Flags == ToSet) 
        return;

    *Flags = MAKEDWORD(ToSet);

}

BOOL HasFlag(DWORD Flags, DWORD ToCheck) {

    return (Flags & ToCheck);

}

