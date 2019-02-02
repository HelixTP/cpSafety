/*
 ============================================================================
 Name        : copyH.c
 Author      : LAD
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

#include "xxhash.h"
#include "xxhsum.h"
#include "copyH.h"

int compute( char* filename){

	return BMK_hash(filename, algo_xxh64, little_endian);
}

int main(int argc, const char** argv) {

	clock_t start, stop;
    char filename[255];
    strcpy(filename, argv[1]);


	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	system("pwd");
	start = clock();

	compute(filename);
	stop = clock();

	printf("executed time : %.3f second\n", (double)(stop - start)/ CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}

/*List *initialisation()
{
    List *list = malloc(sizeof(*list));
    HashFile *hashFile = malloc(sizeof(*hashFile));

    if (list == NULL || hashFile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    hashFile->hash = "Test";
    hashFile->next = NULL;
    list->first = hashFile;

    return list;
}*/
