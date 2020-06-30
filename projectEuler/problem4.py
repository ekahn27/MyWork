"""
SOLVED

A palindromic number reads the same both ways. The largest palindrome made from
the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

def isPalindrome(num):
    """
    Given a integer, return True if it's a palindrome. False otherwise
    """
    numString= str(num)
    return numString == numString[::-1]


def solve4():
    for num in range(997799, 10000, -1):
        if(isPalindrome(num)):
            for threeDigit in range(100, 1000):
                if(num % threeDigit == 0 and len(str(int(num / threeDigit))) == 3):
                    return num

answer= solve4()
print(answer)
