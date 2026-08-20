class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
      
        // Initialize first array with the first element
        vector<int> firstArray = {nums[0]};
      
        // Initialize second array with the second element
        vector<int> secondArray = {nums[1]};
      
        // Process remaining elements starting from index 2
        for (int i = 2; i < n; ++i) {
            // Compare the last elements of both arrays
            if (firstArray.back() > secondArray.back()) {
                // If last element of firstArray is greater, add current element to firstArray
                firstArray.push_back(nums[i]);
            } else {
                // Otherwise, add current element to secondArray
                secondArray.push_back(nums[i]);
            }
        }
      
        // Append all elements from secondArray to the end of firstArray
        firstArray.insert(firstArray.end(), secondArray.begin(), secondArray.end());
      
        // Return the combined result
        return firstArray;
    }
};
