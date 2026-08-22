#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a; // descending order
}

int minimumPushes(const char *word) {
    int ans = 0;
    int count[26] = {0};

    // Count frequency of each letter
    for (int i = 0; word[i] != '\0'; i++) {
        count[word[i] - 'a']++;
    }

    // Sort frequencies in descending order
    qsort(count, 26, sizeof(int), cmp);
    // Calculate pushes
    for (int i = 0; i < 26; i++) {
        ans += count[i] * (i / 8 + 1);
    }

    return ans;
}

int main() {
    const char *word = "leetcode";
    printf("%d\n", minimumPushes(word));
    return 0;
}
