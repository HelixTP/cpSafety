//
// Created by DENIS LALLEMAND on 2019-02-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileHash.h"

Stack new_stack(void)
{
    return NULL;
}
Stack push_hash(Stack st, FileHash x)
{
    StackElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr, "Probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element->fh = x;
    element->next = st;
    return element;
}

Bool is_empty_stack(Stack st)
{
    if(st == NULL)
        return true;

    return false;
}