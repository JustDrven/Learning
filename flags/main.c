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
typedef unsigned int                                    DWORD;
typedef char                                            BOOL;

#define TRUE                                            0x1
#define FALSE                                           0x0


//
//  utilities
//
#define LOG(Value)                                      printf(Value "\n") // fuck...

#define MAKERESORCE(Times)                              ((1) << (Times))   // this only shift left specific bit
#define MAKEDWORD(Value)                                (((DWORD) Value))  // this is unnecessary but, whatever



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



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                                                                           //
//                                I M P L E M E N T A T I O N                                //
//                                                                                           //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//



int main() {

    DWORD Flags;

    //
    //  set flags 
    //
    SetFlag(&Flags, (FLAG_PLAYER_ONLINE | FLAG_PLAYER_ADMIN | FLAG_PLAYER_ALIVE));
    

    printf("Flags: %d\n", Flags);

    //
    //  here should be true
    //
    if (HasFlag(Flags, FLAG_PLAYER_ADMIN))
        LOG("True");
    else
        LOG("False");



    //
    //  here should be true
    //
    if (HasFlag(Flags, FLAG_PLAYER_ALIVE))
        LOG("True");
    else
        LOG("False");


    


    //
    //  here should be false
    //
    if (HasFlag(Flags, FLAG_PLAYER_BANNED))
        LOG("True");
    else
        LOG("False");

    return 0;
}




//
//  helpers
//

void SetFlag(DWORD* Flags, DWORD ToSet) {

    *Flags = MAKEDWORD(ToSet);

}

BOOL HasFlag(DWORD Flags, DWORD ToCheck) {

    return (Flags & ToCheck);

}

