from itertools import count
class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        """
        Find the smallest number >= n whose digit product is divisible by t.
        """

        # Check every number starting from n
        for candidate in count(n):

            # Calculate the product of its digits
            digit_product = 1
            for digit in str(candidate):
                digit_product *= int(digit)

            # If divisible by t, return the number
            if digit_product % t == 0:
                return candidate



def main():
    sol = Solution()
    # Test cases
    tests = [
        (10, 2),
        (10, 3),
        (15, 8),
        (19, 9),
        (100, 5),
        (123, 6),
        (1, 1),
        (7, 7),
        (0, 2),      # Edge case
        (99, 10),
        (256, 12),
    ]
    
    print("Testing smallestNumber()\n")

    for n, t in tests:
        answer = sol.smallestNumber(n, t)
        print(f"n = {n:3}, t = {t:2}  -->  {answer}")

if __name__ == "__main__":
    main()
