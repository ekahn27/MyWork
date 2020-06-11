from math import ceil

def getCombinations(numbers, n, maxSteps, partial):
    """
    numbers= possible numbers for sum
    n= target sum
    maxSteps= most steps for n number of bricks
    partial= a combination being constructed with r values/steps
    """
    if(n < 0): return 0# sum is too big
    elif(len(partial) > maxSteps): return 0# too many steps, elif
    elif(n == 0): return 1#correct soln

    ans= 0
    for index in range(0, len(numbers)):
        ans += getCombinations(numbers[index + 1:], n - numbers[index], maxSteps, partial + [numbers[index]])

    return ans


def solution(n):
    ans= 0
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
        ans= getCombinations(range(1,n), n, maxSteps, [])
    
    else:
        ans= int(ceil(float(n)/2 -1))
    return ans


#Test Cases
#Test Case 1
#answer= solution(200)
#if(answer == 487067745): print("Test case 1 passed!")
#else: print('Test case 0 failed: ' + str(answer) + ' instead of 48706774')

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

#Test Case 6?
#answer= solution(100)
#print(answer)
