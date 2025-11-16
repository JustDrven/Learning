/*+++++++++++++++++++++++++++++++++++++++++++++++
 *
 *  Copyright (c) JustDrven, 2025
 * 
 * ++++++++++++++++++++++++++++++++++++++++++++++
 * 
 *  File: main.c
 *  Author: JustDrven (16-11-2025)
 *
 *  Description
 * +++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      This C file contains funcs and macroes
 *      to manipulate and create access number
 *      
 *      This part could be used as permission
 *      number, which store informations      
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/


//
//  common includes
//

#include <stdio.h>
#include <stdlib.h>



//
//  common typedefs & macroes
//

typedef unsigned int                    NACCESS;

typedef char                            BOOL;
#define TRUE                            0x1
#define FALSE                           0x0




//
//  access masks
//

#define MASK_ACCESS_ID                  0x1FF
#define MASK_ACCESS_TYPE                0x1F
#define MASK_ACCESS_FLAGS               0x1FFFF
#define MASK_ACCESS_ERROR               0x1



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//
//      +----------------------------------------------------------------------------------------+              
//      |                 |                     |                                        |       |              
//      |    Access ID    |     Access Type     |             Flags                      | Error |              
//      |                 |                     |                                        |       |              
//      +----------------------------------------------------------------------------------------+              
//      31      |         23         |          18              |                        1   |   0  Bits        
//              |                    |                          |                            |                  
//              |                    |                          |                            |                  
//              |                    |                          |                            |                  
//              |                    |                          |                            |                  
//              |                    |                          |                            |                  
//              |                    |                          |                            |                  
//              |                    |                          |                            |                  
//    
//         Id of access        Type of access          Access number flags    If access number success or denied
//
//
//
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//
//  Access error codes
//

#define ACCESS_ERROR_OK                 1
#define ACCESS_ERROR_FAIL               0




//
//  Access type codes
//

#define ACCESS_TYPE_SERVER              3
#define ACCESS_TYPE_CLIENT              1






//
//  access token utility
//

#define ACCESS_SUCCESS(Access)          (ACCESS_ERROR_OK == (Access & MASK_ACCESS_ERROR))


NACCESS MakeAccess(int Id, int AccessType, int Flags, BOOL Error) {

    if (Error > 0b1)
        Error = ACCESS_ERROR_FAIL;
    
    return (((Id & MASK_ACCESS_ID) << 23) |
            ((AccessType & MASK_ACCESS_TYPE) << 18) |
            ((Flags & MASK_ACCESS_FLAGS) << 1) | 
            (Error & MASK_ACCESS_ERROR));
    
}








void printInfo(NACCESS accessToken) {

    int accessId = (accessToken >> 23) & MASK_ACCESS_ID;
    int accessType = (accessToken >> 18) & MASK_ACCESS_TYPE;
    int accessFlags = (accessToken >> 1) & MASK_ACCESS_FLAGS;
    int accessError = accessToken & MASK_ACCESS_ERROR;

    printf("\n");
    printf("ID: %d\n", accessId);
    printf("Type: %d\n", accessType);
    printf("Flags: %d\n", accessFlags);
    printf("Error: %d\n", accessError);
    printf("\n");

}


//
//  start entry point
//

int main() {


    //
    //  create access token
    //

    NACCESS access = MakeAccess(
        0x1AF,                   // access id

        ACCESS_TYPE_CLIENT,      // access type is client auth or something like that
        0,

        ACCESS_ERROR_FAIL
    );



    //
    //  print information about access token
    //

    printInfo(access);





    //
    //  check if access token is denied
    //  or allowed
    //

    if (FALSE == ACCESS_SUCCESS(access))        
        printf("Access denied!\n");
    else {
        printf("Access allowed!\n");

        return 1;
    }


    return 0;
}






