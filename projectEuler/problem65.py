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

def sumStringDigits(num):
    """
    Sum the digits of an imput number.
    Using it to find the sum of the numerator. Since the numerator is such a big
    number, the sum only comes out correct by converting the int to a string.
    This way, my argument type is string and I can iterate over each index of
    the string.
    """
    sum= 0
    for digit in num:
        sum += int(digit)
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

    ans= sumStringDigits(str(currVal.numerator))
    return ans

ans= problem65()
print("My answer: " + str(ans))
