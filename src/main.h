//
// Created by DENIS LALLEMAND on 2019-02-13.
//

#ifndef CPSAFETY_MAIN_H
#define CPSAFETY_MAIN_H

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>     /* malloc, calloc, free, exit */
#include "fileHash.h"

#include "xxhash.h"

#ifdef WIN
#include 'inclide/dirent.h'
#endif

// type perso
typedef unsigned long long U64;
typedef enum { big_endian, little_endian} endianess;
//typedef enum { algo_xxh32, algo_xxh64 } algoType;

/* *************************************
*  Constants
***************************************/
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define KB *( 1<<10)
#define MB *( 1<<20)
#define GB *(1U<<30)

#define XXHSUM64_DEFAULT_SEED 0                   /* Default seed for algo_xxh64 */

#endif //CPSAFETY_MAIN_H
