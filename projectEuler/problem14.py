"""
SOLVED

The following iterative sequence is defined for the set of positive integers:

    n → n/2 (n is even)
    n → 3n + 1 (n is odd)

    Using the rule above and starting with 13, we generate the following
    sequence:

    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
    It can be seen that this sequence (starting at 13 and finishing at 1)
    contains 10 terms. Although it has not been proved yet (Collatz Problem), it
    is thought that all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?

    NOTE: Once the chain starts the terms are allowed to go above one million.))))
"""
def collaz(n):
    """
    Return a list of the collaz sequence for positive integer n

    n -> n/2 (if n is even)
    n -> 3n+1 (if n is odd)

    n: list containing one positive integer
    """
    if(n[-1] == 1):
        return n
    if(n[-1] % 2 == 0):
        n.append(int(n[-1]/2))
    else:
        n.append(int(3*n[-1]+1))
    return collaz(n)

def prob14():
    maxLen= 0
    maxNum= 0
    for num in range(1, 1000000):
        currLen= len(collaz([num]))
        if(currLen > maxLen):
            maxLen= currLen
            maxNum= num
    return maxNum

print(prob14())
