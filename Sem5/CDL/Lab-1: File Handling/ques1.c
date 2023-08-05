//To count the number of lines and characters in a file.
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fptr;
    char filename[100];

    char ch;
    int characters, lines;

    printf("Enter filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    characters = lines = 0;
    while ((ch = fgetc(fptr)) != EOF){
        characters++;
        //check new line
        if (ch == '\n')
            lines++;
    }

    //increment lines for last word
    if (characters > 0){
        lines++;
    }

    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total lines      = %d\n", lines);

    fclose(fptr);

    return 0;
}