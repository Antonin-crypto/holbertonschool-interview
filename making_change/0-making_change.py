#!/usr/bin/python3
"""
change comes from within
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet total.

      Args:
        coins (list): List of coin denominations (positive integers)
        total (int): The total amount to reach

      Returns:
        int: Fewest number of coins needed, or -1 if not possible
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
