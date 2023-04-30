#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100   //defining max size

int main() {
    int arr[MAX_SIZE], n;
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Error: the size exceeds the maximum allowed.\n");
        return 1;
    }
    printf("Enter %d integer numbers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    printf("Pairs of points with no values between them:\n");      
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int hasValueBetween = 0;
            for (int k = i+1; k < j; k++) {
                if (arr[k] > arr[i] && arr[k] < arr[j]) {
                    hasValueBetween = 1;
                    break;
                }
            }
            if (!hasValueBetween) {
                printf("(%d,%d), distance: %d\n", arr[i], arr[j], j-i);
                count++;
            }
        }
    }
    if (count == 0) {
        printf("No pairs of points found with no values between them.\n");
    }

    return 0;
}
