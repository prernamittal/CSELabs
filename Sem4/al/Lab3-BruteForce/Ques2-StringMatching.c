#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

int bruteForce(char *str, char *ptr, int slen, int plen) {
    int i, j, k,opcount=0;
    for (i = 0; i <= slen-plen; i++) {
        j=0;
        while((j<plen)&&(ptr[j]==str[j+i])){
            opcount++;
            j++;
        }
        if(j==plen){
        printf("\nOperation Count %d\n",opcount);
        return 1;}
        opcount++;
    }
    printf("\nOperation Count %d\n",opcount);
    return -1;
}

int main() {
    int res;
    char *ptr=(char*)malloc(MAX);
    char *str=(char*)malloc(MAX);
    printf("Enter Search String: ");
    scanf("%s", str);
    printf("Enter Pattern String:");
    scanf("%s", ptr);
    res = bruteForce(str, ptr, strlen(str), strlen(ptr));
    if (res == -1) {
            printf("\nSearch ptr is not available\n");
    } else {
            printf("\nSearch ptr is available\n");
    }
    return 0;
}
