//
// Created by DENIS LALLEMAND on 2019-02-10.
//

#ifndef CPSAFETY_FILEHASH_H
#define CPSAFETY_FILEHASH_H

typedef enum
{
    false, //0
    true //1
}Bool;

typedef struct FileHash{
    char filename[256];
    char path[1024];
    long long int hash;
}FileHash;

/* Définition d'une Pile */
typedef struct StackElement
{
    FileHash fh;
    struct StackElement *next;
}StackElement, *Stack;


Stack new_stack(void);
Bool is_empty_stack(Stack st);
Stack push_stack(Stack st, FileHash x);
Stack pop_stack(Stack st);
Stack clear_stack(Stack st);

#endif //CPSAFETY_FILEHASH_H
