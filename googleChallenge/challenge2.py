import math

def solution(pegs):
    P= -1 * pegs[0]
    for i in range(1, len(pegs)-1):
        P += 2*pow(-1, i-1) * pegs[i]
    P += pow(-1, len(pegs)) * pegs[-1]

    if(len(pegs) % 2 == 1):
        r0= float(P) * float(2)
    else:
        r0= float(P) * float(2) / float(3)
    if(r0 < 1):
        return [-1, -1]
    else:
        fracTuple= r0.as_integer_ratio()
        return [fracTuple[0], fracTuple[1]]


#Test cases Provided
print(solution([4, 30, 50]))
print(solution([4, 17, 50]))
