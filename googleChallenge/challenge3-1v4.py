#Google challenge: Level 3
#The Grandest Staircase of them All
#Correct answer but takes too long for large numbers

from math import ceil

#init arr[n-1][n]
arr= 0
def initArr(n):
    arr= [[-1 for rows in range(n)] for cols in range(n+1)]
    for(i in range(3)):
        for j in range(i,n):
            arr[i][j]= 1

def getCombinations(numbers, n, maxSteps, partial):
    """
    numbers= possible numbers for sum
    n= target sum
    maxSteps= most steps for n number of bricks
    partial= a combination being constructed with r values/steps
    """
#    if(n < 0): return 0# sum is too big
#    elif(len(partial) > maxSteps): return 0# too many steps, elif
#    elif(n == 0): return 1#correct soln
#
#    ans= 0
#    for index in range(0, len(numbers)):
#        ans += getCombinations(numbers[index + 1:], n - numbers[index], maxSteps, partial + [numbers[index]])
#
#    return ans

def KS(num, n):
    if(arr[num][n] != -1): return arr[num][n]
    if(num > n=1 or)
    


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
        initArr(n)
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
