#Level 2 challenge 2
#Bunny Prisoner Locating

def solution(x, y):
    ID= 0
#get initial value along x-axis
    for i in range(1, x+1):
       ID += i
#now go up y-axis to get final value
    currStep= x
    for i in range(1,y):
       ID += currStep
       currStep += 1
    return str(ID)


#Test Cases
#Test 1
if(solution(5,10) == "96"): print("Test case 1 passed!")
else: print("Test case 1 failed")

#Test 2
if(solution(3,2) == "9"): print("Test case 2 passed!")
else: print("Test case 2 failed")

#Test 3
if(solution(1,1) == "1"): print("Test case 3 passed!")
else: print("Test case 3 failed")

#Test 4
if(solution(1,6) == "16"): print("Test case 4 passed!")
else: print("Test case 4 failed")

#Test 5
if(solution(6,1) == "21"): print("Test case 5 passed!")
else: print("Test case 6 failed")
