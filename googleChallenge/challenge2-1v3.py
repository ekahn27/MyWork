#Gearing Up for Destruction: Correct Solution!
from math import pow
from fractions import gcd
from fractions import Fraction

def solution(pegs):
    P= -1 * pegs[0]
    for i in range(1, len(pegs)-1):
        P += 2*pow(-1, i-1) * pegs[i]
    P += pow(-1, len(pegs)) * pegs[-1]

    if(len(pegs) % 2 == 1):
        r0= Fraction(int(P*2), 1)
    else:
        r0= Fraction(int(P*2), 3)

    if(((r0.numerator < 0) ^ (r0.denominator<0)) or (2*r0.denominator > r0.numerator)):
        return [-1, -1]

    else:
        GCD= gcd(r0.numerator, r0.denominator)
        r0= Fraction(int(r0.numerator/GCD), int(r0.denominator/GCD))

    
    prevR= r0
    for i in range(1, len(pegs)-1):
        currR= Fraction(pegs[i], 1) - Fraction(pegs[i-1], 1) - prevR
        if(((currR.numerator<0)^(currR.denominator<0)) or (currR.denominator > currR.numerator)):
            return [-1, -1]
        prevR= currR

    return [r0.numerator, r0.denominator]


#Test Cases Provided
#Test 1
if(solution([4, 30, 50]) == [12,1]): print("Test case 1 passed!")
else: print("Test case 1 failed")

#Test 2
if(solution([4, 17, 50]) == [-1, -1]): print("Test case 2 passed!")
else: print("Test case 2 failed")

#Test 3
if(solution([4, 19]) == [10,1]): print("Test case 3 passed!")
else: print("Test case 3 failed")

#Test 4
if(solution([1,5]) == [8,3]): print("Test case 4 passed!")
else: print("Test case 4 failed")

#Test 5
if(solution([1,4]) == [2,1]): print("Test case 5 passed!")
else: print("Test case 5 failed")

#Test 6
if(solution([1,3]) == [-1,-1]): print("Test case 6 passed!")
else: print("Test case 6 failed")

#Test 7
if(solution([1,2]) == [-1,-1]): print("Test case 7 passed!")
else: print("Test case 7 failed")

#Test 8
if(solution([1,1]) == [-1,-1]): print("Test case 8 passed!")
else: print("Teast case 8 failed")
