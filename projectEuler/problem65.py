"""
SOLVED
Answer: 272

The square root of 2 can be written as an infinite continued fraction.

sqrt(2) = 1 + (1/2+(1/2+(1/2...)))
The infinite continued fraction can be written, sqrt(2)=[1;(2)], (2) indicates that
2 repeats ad infinitum. In a similar way, √23=[4;(1,3,1,8)].

It turns out that the sequence of partial values of continued fractions for
square roots provide the best rational approximations. Let us consider the
convergents for √2.

1+12=3/2  1+12+12=7/5  1+12+12+12=17/12  1+12+12+12+12=41/29
Hence the sequence of the first ten convergents for 2–√ are:

    1,32,75,1712,4129,9970,239169,577408,1393985,33632378,...
    What is most surprising is that the important mathematical constant,
    e=[2;1,2,1,1,4,1,1,6,1,...,1,2k,1,...].

    The first ten terms in the sequence of convergents for e are:

        2,3,83,114,197,8732,10639,19371,1264465,1457536,...
        The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.

        Find the sum of digits in the numerator of the 100th convergent of the
        continued fraction for e.
"""
from fractions import Fraction
from math import floor

def sumDigits(num):
    """
    Sum the digits of an imput number.
    Using it to find the sum of the numerator.
    """
    sum= 0
    while(num >= 1):
        sum += num % 10
        num= int(floor(num / 10))
    return sum


def problem65():
    x= 2
    arr= []
    for i in range(1, 101):
        if(i % 3 == 0):
            arr.append(x)
            x += 2
        else:
            arr.append(1)

    currVal= Fraction(0)
    for index in range(99, 0, -1):
        currVal= Fraction(1, (arr[index] + currVal))
    currVal += 2

    print(currVal.numerator)
    s= str(currVal.numerator)
    one= s[0:10]
    two= s[10:20]
    three= s[20:30]
    four= s[30:40]
    five= s[40:50]
    six= s[50:]

    ans= sumDigits(int(one)) + sumDigits(int(two)) + sumDigits(int(three)) + sumDigits(int(four)) + sumDigits(int(five)) + sumDigits(int(six))

    return ans

ans= problem65()
print("My ans: " + str(ans))
