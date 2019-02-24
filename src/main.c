//
// Created by lad on 1/25/19.
//

#include "main.h"

/*-************************************
*  OS-Specific Includes
**************************************/
#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(_WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>    /* _O_BINARY */
#  include <io.h>       /* _setmode, _isatty */
#  ifdef __MINGW32__
   int _fileno(FILE *stream);   /* MINGW somehow forgets to include this windows declaration into <stdio.h> */
#  endif
#  define SET_BINARY_MODE(file) _setmode(_fileno(file), _O_BINARY)
#  define IS_CONSOLE(stdStream) _isatty(_fileno(stdStream))
#else
#  include <unistd.h>   /* isatty, STDIN_FILENO */
#  define SET_BINARY_MODE(file)
#  define IS_CONSOLE(stdStream) isatty(STDIN_FILENO)
#endif

/* ************************************
*  Display macros
**************************************/
#define DISPLAY(...)         fprintf(stderr, __VA_ARGS__)
#define DISPLAYRESULT(...)   fprintf(stdout, __VA_ARGS__)



static const char stdinName[] = "-";

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

    //Initialise la pile
    Stack sta;
    sta = new_stack();

    sta = ls_dir(argv[1],sta);
    printf("--- End copy ---\n");
    print_stack(sta);
    printf("Hauteur de la pile : %d\n",stack_length(sta));
    //libere la pile
    sta = clear_stack(sta);

    return 0;
}

Stack ls_dir(char*nameDir, Stack sta){

    U64 u64;
    struct dirent* d;
    char pathWithFile[1024];
    XXH64_canonical_t hash;
    char cHash[17] = "";

    //def FileHash
    FileHash fh;

    DIR*dir=opendir(nameDir);
    printf(ANSI_COLOR_GREEN);
    if(dir){
        while( (d=readdir(dir)) ){
            if (!((!(strcmp(d->d_name,"."))) || (!(strcmp(d->d_name,"..")))) ) {
                if (d->d_name[0]!='.') {
                    if (d->d_type == 4) {
                        sprintf(pathWithFile,"%s/%s",nameDir,d->d_name);
                        sta = ls_dir(pathWithFile,sta);
                    }else
                    {
                        sprintf(pathWithFile,"%s/%s",nameDir,d->d_name);
                        u64 = BMK_hash(pathWithFile);

                        XXH64_canonicalFromHash(&hash, u64);
                        BMK_display_BigEndian(&hash, sizeof(hash),cHash);

                        strcpy(fh.path,nameDir);
                        strcpy(fh.filename,d->d_name);
                        strcpy(fh.cHash,cHash);
                        fh.hash = u64;

                        sta = push_stack(sta,fh);

                    }
                }
            }
        }
        closedir(dir);
        printf("Hauteur de la pile :%d\n",stack_length(sta));

    }
    return sta;

}


static void BMK_hashStream(void* xxhHashValue, FILE* inFile, void* buffer, size_t blockSize)
{
    //XXH64_state_t state64;
    XXH64_state_t* state64 = XXH64_createState();

    size_t readSize;

    /* Init */
    XXH64_reset(state64, XXHSUM64_DEFAULT_SEED);

    /* Load file & update hash */
    readSize = 1;
    while (readSize) {
        readSize = fread(buffer, 1, blockSize, inFile);
        XXH64_update(state64, buffer, readSize);
    }
    U64 const h64 = XXH64_digest(state64);
    memcpy(xxhHashValue, &h64, sizeof(h64));
}

U64 BMK_hash(const char* fileName)
{
    FILE*  inFile;
    size_t const blockSize = 64 KB;
    void*  buffer;

    U64    h64 = 0;

    /* Check file existence */
    if (fileName == stdinName) {
        inFile = stdin;
        SET_BINARY_MODE(stdin);
    }
    else
        inFile = fopen( fileName, "rb" );
    if (inFile==NULL) {
        DISPLAY( "Pb opening %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    /* Memory allocation & restrictions */
    buffer = malloc(blockSize);
    if(!buffer) {
        DISPLAY("\nError: not enough memory!\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    /* loading notification */
    {   const size_t fileNameSize = strlen(fileName);
        const char* const fileNameEnd = fileName + fileNameSize;
        const size_t maxInfoFilenameSize = fileNameSize > 30 ? 30 : fileNameSize;
        size_t infoFilenameSize = 1;
        while ( (infoFilenameSize < maxInfoFilenameSize)
                &&(fileNameEnd[-1-infoFilenameSize] != '/')
                &&(fileNameEnd[-1-infoFilenameSize] != '\\') )
            infoFilenameSize++;

        /* Load file & update hash */
        BMK_hashStream(&h64, inFile, buffer, blockSize);

        fclose(inFile);
        free(buffer);
    }
    return h64;
}

static void BMK_display_BigEndian(const void* ptr, size_t length,char *cHash)
{
    char ctmp[3];
    char cHashtmp[17];
    const BYTE* p = (const BYTE*)ptr;
    size_t idx;

    for (idx=0; idx<length; idx++)
    {
        //DISPLAYRESULT("%02x", p[idx]);
        sprintf(ctmp, "%02x", p[idx]);
        strcat(cHashtmp,ctmp);
    }
    //printf(" %s\t",cHashtmp);

    strcpy(cHash,cHashtmp);
}
