"""
SOLVED

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
"""
from imath import isqrt

def isPrime(n):
    """
    Returns True if n is prime, false otherwise

    n: positive integer
    """
    for num in range(2, isqrt(n) + 1):
        if(n % num == 0):
            return False
    return True

def primeFactorize(n, list=[]):
    """
    Gives the prime factors of n
    
    n: integer > 0
    returns: list of integers
    """
    if(isPrime(n)):
        list.append(n)
        return list
    for num in range(2, 1 + isqrt(n)):#2 - ceil(n)
        if(n % num == 0):
            list + primeFactorize(int(n/num), list)
            list + primeFactorize(num, list)

    return list

answer= primeFactorize(600851475143)
print("Answer: " + str(answer))
#print(primeFactorize(1))
#print(primeFactorize(2))
#print(primeFactorize(3))
#print(primeFactorize(4))
#print(primeFactorize(5))
#print(primeFactorize(6))
#print(primeFactorize(7))
