#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]){
    if (argc != 2){
        printf("%s", "file name unknown");
    }


FILE *srcfile = fopen(argv[1], "r");
if (srcfile == NULL){ //error with file
    perror("Error opening file");
    return 1;

}


char *line = NULL;
size_t len = 0;
ssize_t read;


char *last_line1 = NULL;
char *last_line2 = NULL;

while((read = getline(&line, &len, srcfile)) != -1){
    if (last_line2){ //avoiding memory leaks
        free(last_line2);
    }

    last_line2 = last_line1;
    last_line1 = strdup(line);


if (last_line1){
    printf("%s", last_line1);
}

if (last_line2){
    printf("%s", last_line2);
}

free(last_line1);
free(last_line2);
free(line);
fclose(srcfile);

}


//getline(&line, &len, srcfile); //address of pointer, not variable itself

return 0;
}