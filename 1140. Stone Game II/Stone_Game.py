<<<<<<< HEAD
from typing import List
from functools import cache
from itertools import accumulate


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:

        total_piles = len(piles)

        # prefix_sum[i] = sum of piles[0:i]
        prefix_sum = list(accumulate(piles, initial=0))

        @cache


        def dp(start_index: int, max_take: int) -> int:
            """
            
            Maximum stones the current player can obtain
            starting at start_index with M = max_take.
            """

            # If we can take all remaining piles, take them all.
            if max_take * 2 >= total_piles - start_index:
                return prefix_sum[total_piles] - prefix_sum[start_index]

            max_stones = 0


            # Try taking x piles.
            for num_piles_to_take in range(1, 2 * max_take + 1):

                remaining_stones = (
                    prefix_sum[total_piles]
                    - prefix_sum[start_index]
                )

                # Opponent gets their optimal amount.
                opponent_stones = dp(
                    start_index + num_piles_to_take,
                    max(max_take, num_piles_to_take)
                )

                # Whatever opponent doesn't get, we get.
                stones_obtained = remaining_stones - opponent_stones

                max_stones = max(max_stones, stones_obtained)

            return max_stones

        return dp(0, 1)
=======
from typing import List
from functools import cache
from itertools import accumulate

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:

        total_piles = len(piles)

        # prefix_sum[i] = sum of piles[0:i]
        prefix_sum = list(accumulate(piles, initial=0))

        @cache
        def dp(start_index: int, max_take: int) -> int:
            """
            Maximum stones the current player can obtain
            starting at start_index with M = max_take.
            """

            # If we can take all remaining piles, take them all.
            if max_take * 2 >= total_piles - start_index:
                return prefix_sum[total_piles] - prefix_sum[start_index]

            max_stones = 0

            # Try taking x piles.
            for num_piles_to_take in range(1, 2 * max_take + 1):

                remaining_stones = (
                    prefix_sum[total_piles]
                    - prefix_sum[start_index]
                )

                # Opponent gets their optimal amount.
                opponent_stones = dp(
                    start_index + num_piles_to_take,
                    max(max_take, num_piles_to_take)
                )

                # Whatever opponent doesn't get, we get.
                stones_obtained = remaining_stones - opponent_stones

                max_stones = max(max_stones, stones_obtained)

            return max_stoness
        return dp(0, 1)
>>>>>>> origin/main
