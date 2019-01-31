/*
 * copyH.h
 *
 *  Created on: 12 févr. 2018
 *      Author: lad
 */

#ifndef COPYH_H_
#define COPYH_H_



#endif /* COPYH_H_ */

// liste chainée pour la sauvegarde de la liste des fichiers
typedef struct HashFile HashFile;
struct HashFile
{
    char hash[17] ;
    char path[1024];
    char name[256];
    HashFile *next;
};
// control the list
typedef struct List List;
struct List
{
	HashFile *first;
};
