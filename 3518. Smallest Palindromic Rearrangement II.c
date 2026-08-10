#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 1000001

// Helper function to calculate combinations: n Choose k
static long long nCk(int n, int k) {
    int limit = (k < n - k) ? k : (n - k);
    long long res = 1;
    for (int i = 1; i <= limit; i++) {
        res = res * (n - i + 1) / i;
        if (res >= MAX_LIMIT) {
            return MAX_LIMIT;
        }
    }
    
    return res;
}

// Calculates total permutations using multinomial coefficient logic
static long long countArrangements(int halfCount[26]) {
    int total = 0;
    for (int i = 0; i < 26; i++) {
        total += halfCount[i];
    }

    long long res = 1;
    for (int i = 0; i < 26; i++) {
        if (halfCount[i] > 0) {
            res *= nCk(total, halfCount[i]);
            if (res >= MAX_LIMIT) {
                return MAX_LIMIT;
            }
            total -= halfCount[i];
        }
    }
    return res;
}

// Main function to return the k-th lexicographically smallest palindrome
char* smallestPalindrome(const char* s, int k) {
    int count[26] = {0};
    int len = 0;
    while (s[len] != '\0') {
        count[s[len] - 'a']++;
        len++;
    }

    // Check if palindrome formation is possible
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }
    }
    if (oddCount > 1) {
        return strdup("");
    }

    // Get half counts and the middle character if string length is odd
    int halfCount[26] = {0};
    char midLetter = '\0';
    int halfLen = 0;

    for (int i = 0; i < 26; i++) {
        halfCount[i] = count[i] / 2;
        halfLen += halfCount[i];
        if (count[i] % 2 != 0) {
            midLetter = (char)('a' + i);
        }
    }

    // Check total valid arrangements
    long long totalPerm = countArrangements(halfCount);
    if (k > totalPerm) {
        return strdup("");
    }

    // Allocate memory for the output string + null terminator
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    if (!result) return NULL;

    int leftIdx = 0;
    long long currentK = k;

    // Build the left half character by character
    for (int step = 0; step < halfLen; step++) {
        for (int i = 0; i < 26; i++) {
            if (halfCount[i] == 0) continue;

            halfCount[i]--;
            long long arrangements = countArrangements(halfCount);

            if (arrangements >= currentK) {
                result[leftIdx++] = (char)('a' + i);
                break;
            } else {
                currentK -= arrangements;
                halfCount[i]++;
            }
        }
    }

    // Fill middle character if present
    int rightIdx = len - 1;
    if (midLetter != '\0') {
        result[halfLen] = midLetter;
    }

    // Fill the right half by mirroring the left half
    for (int i = 0; i < halfLen; i++) {
        result[rightIdx - i] = result[i];
    }

    result[len] = '\0';
    return result;
}
