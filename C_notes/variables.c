#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the lexicographically smallest palindrome
char* smallestPalindrome(char* s) {

    // Array to count frequency of each lowercase letter
    // freq[0] -> 'a'
    // freq[1] -> 'b'
    // ...
    // freq[25] -> 'z'
    int freq[26] = {0};

    // Length of the input string
    int n = strlen(s);

    // Count the frequency of every character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Allocate memory for the answer (+1 for '\0')
    char *ans = (char *)malloc((n + 1) * sizeof(char));

    // Two pointers
    int left = 0;
    int right = n - 1;

    // Stores the middle character if one exists
    char middle = '\0';

    // Process letters from 'a' to 'z'
    for (int i = 0; i < 26; i++) {

        // Place pairs of the current character
        while (freq[i] >= 2) {

            // Put one copy on the left
            ans[left] = 'a' + i;
            left++;

            // Put one copy on the right
            ans[right] = 'a' + i;
            right--;

            // Two copies have been used
            freq[i] -= 2;
        }

        // If one copy remains, it becomes the middle character
        if (freq[i] == 1) {
            middle = 'a' + i;
        }
    }

    // Put the middle character (only for odd-length strings)
    if (middle != '\0') {
        ans[left] = middle;
    }

    // End the string
    ans[n] = '\0';

    return ans;
}

int main() {

    char s1[] = "z";
    char s2[] = "babab";
    char s3[] = "daccad";

    char *p1 = smallestPalindrome(s1);
    char *p2 = smallestPalindrome(s2);
    char *p3 = smallestPalindrome(s3);

    printf("Input : %s\n", s1);
    printf("Output: %s\n\n", p1);

    printf("Input : %s\n", s2);
    printf("Output: %s\n\n", p2);

    printf("Input : %s\n", s3);
    printf("Output: %s\n\n", p3);

    // Free allocated memory
    free(p1);
    free(p2);
    free(p3);

    return 0;
}