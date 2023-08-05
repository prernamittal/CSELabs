#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr1, *fptr2;
    char ch, filename[30], newch[500];
    int i=0, j, count=0;

    printf("Enter filename: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");

    fseek(fptr1,0,SEEK_END);
    int size=ftell(fptr1);
    printf("size of file is: %d bytes\n", size);

    if (fptr1 == NULL){
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    
    //original content
    ch = getc(fptr1);
    while(ch != EOF){
        count++;
        newch[i] = ch;
        i++;
        ch = getc(fptr1);
    }

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w+"); // Open another file for writing

    //reverse content
    for(j=(count-1); j>=0; j--) {
        ch = newch[j];
        fprintf(fptr2,"%c",ch);
    }

    fclose(fptr2);

    printf("Entered reversed content to %s\n", filename);

    return 0;
}
