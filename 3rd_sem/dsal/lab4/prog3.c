#include<stdio.h>
#include<string.h>
void check(char word[], int index)
{
    int len=strlen(word)-(index+1);
    if(word[index]==word[len])
    {
        if((index+1==len)||(index==len))
        {
            printf("palindrome");
            return;
        }
        check(word,index+1);
    }
    else
    {
        printf("not a palindrome");
    }
}
int main()
{
    char word[50];
    printf("Enter word: ");
    scanf("%s", word);
    check(word,0);
    return 0;
}
