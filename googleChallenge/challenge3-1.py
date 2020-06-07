#google challenge: Level 3
#The Grandest Staircase of them All

def sum_numbers(numbers, n, partial=[]):
    ans= 0
    s= sum(partial)

    if (s == n):
        print(partial)
        return 1
    if (s > n):
        return 0

    for i in range(len(numbers)):
        addToPartial= numbers[i]
        remaining= numbers[i+1:]
        ans += sum_numbers(remaining, n, partial+[n])

    return ans


def solution(n):
    return sum_numbers(range(1, n-1), n) 



print(solution(3))
print(solution(4))
print(solution(5))
