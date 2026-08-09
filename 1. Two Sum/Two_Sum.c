#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1009   // Prime number

typedef struct Node
{
    int key;            // number
    int value;          // index
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

// Hash function
int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % TABLE_SIZE;
}

// Insert number and its index
void insert(int key, int value)
{
    int index = hash(key);

    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

// Search for a number
int search(int key)
{
    int index = hash(key); // index = 11

    Node *current = hashTable[index];
    /*
    hashTable[11]
      │
      ▼
+------------+
| key = 11   |
| value = 2  |
| next = NULL|
+------------+

so current = hashTable[11] => current->key = 11, current->value = 2, current->next = NULL
    */

    while (current != NULL)
    {
        if (current->key == key)
            return current->value;

        current = current->next;
    }

    return -1;
}

// Free memory
void freeTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *current = hashTable[i];

        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void Two_Sum(int nums[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        int complement = target - nums[i];

        int index = search(complement);

        if (index != -1)
        {
            printf("[%d,%d]\n", index, i);
            return;
        }

        insert(nums[i], i);
    }

    printf("No solution\n");
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 26;
    int size = sizeof(nums) / sizeof(nums[0]);

    Two_Sum(nums, target, size);

    freeTable();

    return 0;
}
