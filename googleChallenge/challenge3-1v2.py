#attempt 2 at challeng3-1
from math import ceil
from itertools import combinations

def getCombinations(numbers, r, n):
    """
    Given a list of numbers, <numbers>, an amount to choose <r> and a target
    value <n>, calculate all combinations, nCr, and return the number of
    combinations that sum to n
    """
    ans= 0
    combos= list(combinations(numbers, r))
    for combination in combos:
        if(sum(combination) == n):
            ans += 1
    return ans


def solution(n):
#num of steps possible w/ 2 steps
    ans= int(ceil(float(n)/2 -1))
#calculate max num steps
    if(n >= 6):
        tempSum= 0
        incr= 1
        maxSteps= 0
        while(tempSum < n):
            tempSum += incr
            incr +=1
            if(tempSum <= n):
                maxSteps +=1

        for steps in range(3, maxSteps+1):
#get biggest possible value in summation for given number of steps
#n - sum(1,steps)
            mostBricksForSingleStep= n - sum(range(1,steps))
#end of that calc
            ans += getCombinations(range(1, mostBricksForSingleStep+1), steps, n)
    return ans


#Test Cases
#Test Case 1
answer= solution(200)
if(answer == 487067745): print("Test case 1 passed!")
else: print('Test case 0 failed: ' + str(answer) + ' instead of 48706774')

##Test Case 2
#answer= solution(3)
#if(answer == 1): print('Test case 2 passed!')
#else: print('Test case 2 failed: ' + str(answer) + ' instead of 1')
#
##Test Case 3
#answer= solution(5)
#if(answer == 2): print('Test case 3 passed!')
#else: print('Test case 3 failed: ' + str(answer) + ' instead of 2')
#
##Test Case 4
#answer= solution(6)
#if(answer == 3): print('Test case 4 passed!')
#else: print('Test case 4 failed: ' + str(answer) + ' instead of 6')
#
##Test Case 5
#answer= solution(10)
#if(answer == 9): print('Test case 5 passed!')
#else: print('Test case 5 failed: ' + str(answer) + ' instead of 9')
