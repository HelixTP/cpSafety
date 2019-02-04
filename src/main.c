//
// Created by lad on 1/25/19.
//

#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include <ncurses.h>

void ls_dir(char*nameDir);

int main (int argc, char *argv[])
{
    initscr();

    if(argc > 1){
        printw("nombre d'argument : %d\n",argc);
        for (int i = 1;i < argc; ++i) {
            printw("%s\t",argv[i]);
        }
    } else {
        printw("Pas d'argument \n");
    }
    printw("\n");
    printw("--- Begin copy ---\n");
    ls_dir(argv[1]);
    printw("--- End copy ---\n");
    
    refresh(); 
    getch();
    endwin();
    return 0;
}

void ls_dir(char*nameDir){

    DIR*dir=opendir(nameDir);
    struct dirent* d;

    if(dir){
        while( (d=readdir(dir)) ){
            if (!((!(strcmp(d->d_name,"."))) || (!(strcmp(d->d_name,"..")))) ) {
                if (!(d->d_name[0]=='.')) {
                    printw("%s and dir type %d\n ",d->d_name, d->d_type);
                }              
            } 
        }
        closedir(dir);
    }
}