//
// Created by lad on 1/25/19.
//

#include <stdio.h>
#include <dirent.h>

void ls_dir(char*nameDir);

int main (int argc, char *argv[])
{
    if(argc > 1){
        printf("nombre d'argument : %d\n",argc);
        for (int i = 1;i < argc; ++i) {
            printf("%s\t",argv[i]);
        }
    } else {
        printf("Pas d'argument \n");
    }
    printf("\n");
    printf("--- Begin copy ---\n");
    ls_dir(".");
    printf("--- End copy ---\n");

    return 0;
}


void ls_dir(char*nameDir){

    DIR*dir=opendir(nameDir);
    struct dirent* d;

    if(dir){
        while( (d=readdir(dir)) ){
            printf("%s\n",d->d_name);
        }
        closedir(dir);
    }
}