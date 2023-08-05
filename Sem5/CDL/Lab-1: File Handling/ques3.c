#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fptr1, *fptr2, *fp;
	char ch1 = 'a', ch2 = 'a';
    char filename[30];

    printf("Enter the filename1: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");

    printf("Enter filename2: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "r");

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);
    fp = fopen(filename, "w+"); // Open another file for writing

    if (fptr1 == NULL || fptr2 == NULL){
    printf("Cannot open file %s \n", filename);
    exit(0);
    }
	
	while (ch1 != EOF || ch2 != EOF){
		if (ch1 != EOF){
			ch1 = fgetc(fptr1);
			//A line ends when \n is encountered
			while (ch1 != '\n'){
				if (ch1 == EOF)
					break;
				fputc(ch1, fp);
				ch1 = fgetc(fptr1);
			}
			if (ch1 != EOF)
				fputc('\n', fp);
		}
		if (ch2 != EOF){
			ch2 = fgetc(fptr2);
			while (ch2 != '\n')
			{
				if (ch2 == EOF)
					break;
				fputc(ch2, fp);
				ch2 = fgetc(fptr2);
			}
			if (ch2 != EOF)
				fputc('\n', fp);
		}
	}
	printf("\nTask completed.\n");
	return 0;
}