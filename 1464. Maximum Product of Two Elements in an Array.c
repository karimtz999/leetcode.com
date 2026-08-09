
#include <stdio.h>


int maxProduct(int* nums, int numsSize) {
    int first_max = 0, second_max = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > first_max) {
            second_max = first_max;
            first_max = nums[i];
        } else if (nums[i] > second_max) {
            second_max = nums[i];
        }
        
    }

    

    return (first_max - 1) * (second_max - 1);
    
    
}


// Example usage
int main() {
    
    int nums[] = {2, 1, 5, 6, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum Product: %d\n", maxProduct(nums, size));
    return 0;
}




