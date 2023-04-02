#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j,count;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n], freq[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;  //init ele
    }
    for (i = 0; i < n; i++) {
        count = 1;  
        for (j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;  
                freq[j] = 0;  //counted ele
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;  //store freq
        }
    }
    for (i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("Element:%d\tCount:%d\n", arr[i], freq[i]);  
        }
    }
    return 0;
}