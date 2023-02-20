#include <stdio.h>

void bubbleSort(int list[], int n){
  int t,opcount=0;
  for (int i= 0;i<=n-2;i++) {
    for (int j=0;j<n-i-1;j++) {
        ++opcount;
      if (list[j]>list[j+1]) {
        ++opcount;
        t= list[j];
        list[j]= list[j+1];
        list[j+1]= t;
      }
    }
  }
  printf("\nOperation Count %d\n",opcount);
}

int main(){
  int array[30], n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter %d integers:\n", n);
  for (int i=0;i<n;i++)
    scanf("%d", &array[i]);
  bubbleSort(array, n);
  printf("Sorted list in ascending order:\n");
  for (int i=0;i<n;i++)
     printf("%d\t", array[i]);
  return 0;
}