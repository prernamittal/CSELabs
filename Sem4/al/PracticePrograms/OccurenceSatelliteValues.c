#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n], freq[n],unique[n];
    int count = 0, found;
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;  //init ele
    }
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < count; j++) {
            if (arr[i] == unique[j]) { // element already exists in unique array
                found = 1;
                freq[j]++; // increment frequency
                break;
            }
        }
        if (!found) { // add element to unique array
            unique[count] = arr[i];
            freq[count] = 1;
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        printf("Number:%d Count:%d\n", unique[i], freq[i]);
    }
    return 0;
}
