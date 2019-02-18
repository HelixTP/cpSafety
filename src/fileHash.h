//
// Created by DENIS LALLEMAND on 2019-02-10.
//

#ifndef CPSAFETY_FILEHASH_H
#define CPSAFETY_FILEHASH_H


typedef struct fileHash{
    char filename[256];
    char path[1024];
    long long int hash;
    struct fileHash *next;
}fileHash, Hash;

Hash new_hash(void);

#endif //CPSAFETY_FILEHASH_H
