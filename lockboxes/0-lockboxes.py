#!/usr/bin/python3
""" Method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """ Method that determines if all the boxes can be opened """
    unlocked = [0]
    n = len(boxes)
    for i in unlocked:
        for key in boxes[i]:
            if key not in unlocked and key < n:
                unlocked.append(key)
    if len(unlocked) == n:
        return True
    return False
