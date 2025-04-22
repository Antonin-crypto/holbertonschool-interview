#!/usr/bin/python3

def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls (list): A list of non-negative integers representing

    Returns:
        int: Total amount of water retained.
    """
    # Edge case: if the list is empty or has fewer than 3 walls
    if len(walls) < 3:
        return 0

    # Initialize arrays to store the maximum heights from the left and right
    left_max = [0] * len(walls)
    right_max = [0] * len(walls)

    # Fill the left_max array
    left_max[0] = walls[0]
    for i in range(1, len(walls)):
        left_max[i] = max(left_max[i-1], walls[i])

    # Fill the right_max array
    right_max[len(walls) - 1] = walls[len(walls) - 1]
    for i in range(len(walls) - 2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])

    # Calculate the total amount of water retained
    water_retained = 0
    for i in range(1, len(walls) - 1):
        # and the height of the wall at index i
        water_retained += max(0, min(left_max[i], right_max[i]) - walls[i])

    return water_retained
