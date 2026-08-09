class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        from functools import cache
        from itertools import accumulate
        from typing import List
      
        @cache
        def dp(start_index: int, max_take: int) -> int:
            """
            Calculate the maximum stones the current player can get starting from start_index
            with the ability to take up to 2 * max_take piles.
          
            Args:
                start_index: Current position in the piles array
                max_take: Current M value (maximum X from previous turn)
          
            Returns:
                Maximum stones the current player can collect from this state
            """
            # If we can take all remaining piles, take them all
            if max_take * 2 >= total_piles - start_index:
                return prefix_sum[total_piles] - prefix_sum[start_index]
          
            # Try taking x piles (1 <= x <= 2 * max_take) and find the maximum outcome
            # The current player's score = total remaining stones - opponent's best score
            max_stones = 0
            for num_piles_to_take in range(1, 2 * max_take + 1):
                # Calculate stones we get: total remaining - what opponent gets optimally
                stones_obtained = prefix_sum[total_piles] - prefix_sum[start_index] - \
                                 dp(start_index + num_piles_to_take, 
                                   max(max_take, num_piles_to_take))
                max_stones = max(max_stones, stones_obtained)
          
            return max_stones
      
        # Initialize variables
        total_piles = len(piles)
        # Create prefix sum array for quick range sum calculation
        # prefix_sum[i] = sum of piles[0:i]
        prefix_sum = list(accumulate(piles, initial=0))
      
        # Start the game from index 0 with M = 1
        return dp(0, 1)