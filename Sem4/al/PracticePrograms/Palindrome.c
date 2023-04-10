#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n], freq[10] = {0}, mid = -1;
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;  // count the frequency of each digit
    }

    for (i = 0; i < 10; i++) {
        if (freq[i] % 2 == 1) {
            if (mid == -1) {
                mid = i;  // assign a digit to the middle of the palindrome
            }
        }
    }

    char palindrome[n + 1];  // create a character array to store the palindrome
    for (i = 0; i < 10; i++) {
        for (j = 0; j < freq[i] / 2; j++) {
            palindrome[k++] = i + '0';  // add the digits to the left half of the palindrome
        }
    }

    if (mid != -1) {
        palindrome[k++] = mid + '0';  // add the middle digit to the middle of the palindrome
    }

    for (i = k - 2; i >= 0; i--) {
        palindrome[k++] = palindrome[i];  // add the reverse of the left half to the right half
    }

    palindrome[k] = '\0';  // terminate the string with null character
    printf("Longest possible palindrome: %s\n", palindrome);
    return 0;
}
