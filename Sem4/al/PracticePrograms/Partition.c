#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int set[n], p[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &set[i]);
        p[i] = -1;  // init all elements to -1
        sum += set[i];
    }

    if (!(sum % 2 == 0)){
        printf("Partition not possible\n");
        return 0;
    }

    int half = sum / 2, currsum;
    for (i = 0; i < n; i++) {
        currsum = half;
        for (j = i; j < n; j++) {
            if (currsum >= set[j]) {
                currsum -= set[j];
                p[j] = i;  // assign j to partition i
            } 
        }
        if (currsum == 0) {
            break;
        }
    }

    if (currsum == 0) {
        printf("Partition possible\n");
        printf("\nPartition 1: ");
        for (i = 0; i < n; i++) {
            if (p[i] == 0) {
                printf("%d ", set[i]);
            }
        }
        printf("\nPartition 2: ");
        for (i = 0; i < n; i++) {
            if (p[i] == 1) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
    } 

    return 0;
}
