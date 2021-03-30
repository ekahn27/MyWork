from random import randint
from math import ceil

numCandidates= 1000
numChosen= 50
workVal= 0.95
luckVal= 1-workVal

class Person():
    def __init__(self):
        self.work= randint(0, 100)
        self.luck= randint(0, 100)
        self.total= workVal*self.work + luckVal*self.luck

    def __str__(self):
        "{:.2f}".format(self.work * workVal)
        return "work: "+ "{:.2f}".format(self.work * workVal) + "   luck: " + "{:.2f}".format(self.luck * luckVal) + "   Total:"+str(self.total)

def binSearchPeople(arr, newPerson, left, right):
    """
    Find index to insert Person object and return it.
    """
    while(left <= right):#fix
        pivotIndex= ceil((right + left)/2)
        if(newPerson.total < arr[pivotIndex].total):
            left= pivotIndex + 1
        elif(newPerson.total > arr[pivotIndex].total):
            right= pivotIndex - 1
        else:
            return pivotIndex
    return left;

candidates= []

for index in range(numCandidates):
    newPerson= Person()
    insertIndex= binSearchPeople(candidates, newPerson, 0, len(candidates)-1)
    candidates.insert(insertIndex, newPerson)

for i in range(0,10):
    print(candidates[i])
