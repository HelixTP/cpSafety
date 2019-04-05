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

// type perso
typedef unsigned long long U64;
typedef unsigned char      BYTE;
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

//function
static void BMK_hashStream(void* xxhHashValue, FILE* inFile, void* buffer, size_t blockSize);
U64 BMK_hash(const char* fileName);
static void BMK_display_BigEndian(const void* ptr, size_t length,char *cHash);
static void BMK_display_LittleEndian(const void* ptr, size_t length,char *cHash);
Stack ls_dir(char*nameDir,Stack sta);
int compute( char* filename);

