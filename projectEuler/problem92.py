"""
SOLVED

A number chain is created by continuously adding the square of the digits in a
number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless
loop. What is most amazing is that EVERY starting number will eventually arrive
at 1 or 89.

How many starting numbers below ten million will arrive at 89?
"""

def getDigits(num):
    """
    returns a list of the individual numbers in an integer

    ex: getDigits(123), returns [1,2,3]
    """
    list= []
    while(num >= 1):
        newVal= int(num % 10)
        list.append(newVal)
        num= int((num - newVal)/10)
    return list

def lastValOfChain(n):
    """
    returns the last value (1 or 89) in the number chain specified above
    """
    while(n != 1 and n != 89):
        digits= getDigits(n)
        n= 0
        for digit in digits:
            n += digit*digit
    return n

def prob92():
    """
    Call lastValOfChain() enough times to figure out how many chains end with 89
    """
    ans= 0
    for num in range(1, 10000000):
        if(lastValOfChain(num) == 89):
            ans += 1
    return ans


print(prob92())
