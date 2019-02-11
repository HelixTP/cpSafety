//
// Created by lad on 1/25/19.
//

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "fileHash.h"

#include "xxhash.h"
#include "xxhsum.h"

#ifdef WIN
    #include 'inclide/dirent.h'
#endif

// type perso
typedef unsigned long long U64;

//#include <ncurses.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void ls_dir(char*nameDir);
int compute( char* filename);

int main (int argc, char *argv[])
{
    //initscr();
  printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");
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
    ls_dir(argv[1]);
    printf("--- End copy ---\n");
    
    //refresh(); 
    //getch();
    //endwin();
    return 0;
}

void ls_dir(char*nameDir){

    //struct fileHash current;
    struct dirent* d;
    char pathWithFile[1024];

    DIR*dir=opendir(nameDir);
    printf(ANSI_COLOR_GREEN);
    if(dir){
        while( (d=readdir(dir)) ){
            if (!((!(strcmp(d->d_name,"."))) || (!(strcmp(d->d_name,"..")))) ) {
                if (d->d_name[0]!='.') {
                    if (d->d_type == 4) {
/*                        printf("----------Directory-------- ");
                        printf("%s+%s\n",nameDir,d->d_name);*/
                        sprintf(pathWithFile,"%s/%s",nameDir,d->d_name);
                        ls_dir(pathWithFile);
                    }else
                    {
                        sprintf(pathWithFile,"%s/%s",nameDir,d->d_name);
                        compute(pathWithFile);
                        printf("%s\n",pathWithFile);
                    }
                }
            }
        }
        closedir(dir);

    }
}
int compute( char* filename){
    U64 u64;
    //U64 hashResult;
    return BMK_hash_LAD(filename, algo_xxh64, little_endian, u64);
}