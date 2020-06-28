"""
problem 35: SOLVED

The number, 197, is called a circular prime because all rotations of the digits:
197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
71, 73, 79, and 97.

How many circular primes are there below one million?
"""
from math import isqrt
from math import floor

circularPrimes=[2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97]

def isPrime(n):
    """
    Return True is n is prime and false if not

    n: a positive integer
    return: bool
    """
    for num in range(2, int(isqrt(n)+1)):
        if(n % num == 0):
            return False
    return True

def rotateNum(num):
    """
    Given an integer, <num>, rotate the number once and return it.
    This means that given the number 123, the number 231 is returned.
    """
    temp= num
    cnt= 1
    while(temp > 10):
        temp /= 10
        cnt += 1
    ones= int(floor(temp))
    lastNum= temp - ones
    for tens in range(0, cnt):
        lastNum *= 10
    lastNum += ones
    return round(lastNum)

def numOfDigits(n):
    """
    returns the number of digits in the given integer <n>.
    """
    cnt= 1
    while(n > 10):
        n /= 10
        cnt += 1
    return cnt

def containsEvenDigit(n):
    """
    Erros because rotating a number with a zero in it and converting to an int
    causes wrong numbers. I then improved it to check if the number contains
    any even digits by mod-ing 2 instead of mod-ing 10.
    E.g. 103 becomes 031 which is 31 and 310 is not accounted for.
    """
    while(n >= 1):
        if(n % 2 == 0):
            return True
        n= floor(n / 10)
    return False

def checkCircularness(n):
    circularList= [n]
    numOfRotations= numOfDigits(n) - 1
    for rotation in range(0, numOfRotations):
        n= rotateNum(n)
        if(not isPrime(n)):
            return
        circularList.append(n)
    for elem in circularList:
        if(elem not in circularPrimes):
            circularPrimes.append(elem)

def prob35():
    for num in range(101, 1000000, 2):
    #for num in range(101, 200, 2):
        if(isPrime(num) and (num not in circularPrimes) and (not containsEvenDigit(num))):
            checkCircularness(num)
    print(circularPrimes)
    return len(circularPrimes)


ans= prob35()
print("Answer to problem 35 is: " + str(ans))
