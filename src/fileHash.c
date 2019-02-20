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
Stack push_stack(Stack st, FileHash x)
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

Stack pop_stack(Stack st)
{
    StackElement *element;

    if(is_empty_stack(st))
        return new_stack();

    element = st->next;
    free(st);

    return element;
}

Stack clear_stack(Stack st)
{
    while(!is_empty_stack(st))
        st = pop_stack(st);

    return new_stack();
}
