#include <stdio.h>
void towers(int n, char from, char top, char temp)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", from, top);
        return;
    }
    towers(n-1, from, temp, top);
    printf("\n Move disk %d from peg %c to peg %c", n, from, top);
    towers(n-1, temp, top, from);
}
int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves :\n");
    towers(n, 'A', 'C', 'B');
    return 0;
}

