#include <stdio.h>

int gcd(int a, int b){//eucledian algo
    int r;
    while(b!=0) { 
    r = a %b; 
    a = b; 
    b=r; 
    } 
    return a; 
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int maxdiv = 0;
    for (int i = 2; i < max; i++) {
        if (max % i == 0) {
            maxdiv = i;
        }
    }

    int mindiv = 0;
    for (int i = 2; i < min; i++) {
        if (min % i == 0) {
            mindiv = i;
        }
    }

    int gcddiv = gcd(maxdiv, mindiv);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("GCD (%d,%d) = %d\n", maxdiv, mindiv, gcddiv);

    return 0;
}
