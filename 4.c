#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char s[MAX_LEN + 1];
    int x, y;
    printf("Enter the string s (up to %d characters): ", MAX_LEN);
    scanf("%s", s);
    printf("Enter the integer values x and y: ");
    scanf("%d %d", &x, &y);

    int len = strlen(s);
    int points = 0;
    int i = 0;
    while (i < len) {
        if (i+1 < len && s[i] == 'a' && s[i+1] == 'b') {
            points += x;            // Removing "ab"    
            i += 2;
        } else if (i+1 < len && s[i] == 'b' && s[i+1] == 'a') {
            points += y;           // Removing "ba"
            i += 2;
        } else if (i+2 < len && (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a') ||
                   (s[i] == 'b' && s[i+1] == 'a' && s[i+2] == 'b')) {
            points += x + y;       // Removing "aba" or "bab"
            i += 3;
        } else if (i+2 < len && (s[i] == 'a' && s[i+1] == 'a' && s[i+2] == 'a') ||
                   (s[i] == 'b' && s[i+1] == 'b' && s[i+2] == 'b')) {
            points += x * y;       // Removing "aaa" or "bbb"
            i += 3;
        } else {
            i++;
        }
    }

    printf("Maximum points: %d\n", points);

    return 0;
}
