#!/usr/bin/python3
""" Doc """


def minOperations(n):
    """ 
    write a method that calculates the fewest number of operations needed
    to result in exactly n H characters in the file.
    """
    if n <= 1:
        return 0
    num = 0
    i = 2
    
    while i <= n:
        while n % i == 0:
            num += i
            n //= i
        i += 1
    return num
