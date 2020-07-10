"""
It was proposed by Christian Goldbach that every odd composite number can be
written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime
and twice a square?
"""
from math import isqrt

primes= [1,3,5,7,11,13,17,19,23,29,31]

def isComposite(num):
    for i in range(3, isqrt(num)):
        if(num % i == 0):
            return True
    primes.append(num)
    return False

def prob46():
    num= 35
    while (True):
        if(isComposite(num)):
            doReturn= True
            for prime in primes:
                #check if prime + 2*square
                temp= 0
                sqr= 1
                while(temp <= num):
                    temp= prime + 2*sqr*sqr
                    if(temp == num):
                        doReturn= False
                    sqr += 1
            if(doReturn):
                return num
        num += 2

print(prob46())
