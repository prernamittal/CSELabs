#include <stdio.h>
int main()
{
    char str1[50],str2[50];
    printf("Enter string: ");
    scanf("%s[^\n]", str1);
    copy(str1,str2,0);
    printf("1st string: %s\n", str1);
    printf("2nd string: %s\n", str2);
    return 0;
}
void copy(char str1[],char str2[],int index)
{
    str2[index]=str1[index];
    if(str1[index]=='\0')
    {
        return;
    }
    copy(str1,str2,index+1);

}