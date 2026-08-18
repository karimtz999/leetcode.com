class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        """
        Find the largest integer based on position k and uniqueness constraints.
      
        Args:
            nums: List of integers
            k: Position parameter that determines the algorithm behavior
          
        Returns:
            The largest valid integer based on the constraints, or -1 if none exists
        """
      
        def find_unique_boundary_value(position: int) -> int:
            """
            Check if the value at given position is unique in the array.
          
            Args:
                position: Index position to check
              
            Returns:
                The value at position if it's unique, otherwise -1
            """
            # Check if this value appears elsewhere in the array
            for index, value in enumerate(nums):
                if index != position and value == nums[position]:
                    return -1  # Value is not unique
            return nums[position]  # Value is unique, return it
      
        # Special case 1: When k = 1, find the maximum value that appears exactly once
        if k == 1:
            from collections import Counter
            frequency_map = Counter(nums)
            # Find all values with frequency 1 and return the maximum
            unique_values = (value for value, count in frequency_map.items() if count == 1)
            return max(unique_values, default=-1)
      
        # Special case 2: When k equals array length, return the maximum value
        if k == len(nums):
            return max(nums)
      
        # General case: Check both boundaries (first and last positions)
        # Return the maximum of unique values at boundaries
        first_position_value = find_unique_boundary_value(0)
        last_position_value = find_unique_boundary_value(len(nums) - 1)
        return max(first_position_value, last_position_value)
