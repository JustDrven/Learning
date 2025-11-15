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
 *      This C file contains method to
 *      share functions between two diffrent 
 *      types of programming languages
 * 
 *      Example: If you want do function in 
 *               assembly and use that func
 *               in C. You can use "extern" 
 *               annotation
 *
 +++++++++++++++++++++++++++++++++++++++++++++++*/


extern void print(char*);

int main() {

    print("Hello");

    return 0;
}
