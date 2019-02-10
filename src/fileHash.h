//
// Created by DENIS LALLEMAND on 2019-02-10.
//

#ifndef CPSAFETY_FILEHASH_H
#define CPSAFETY_FILEHASH_H


struct fileHash{
    char filename[256];
    char path[1024];
    char hash[10];
}fileHash;


#endif //CPSAFETY_FILEHASH_H
