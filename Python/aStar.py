from graph2 import *
from math import pow
from math import sqrt
#A* implementation

#list Frontier: All nodes in Frontier set where shortest known length from
#start to the node is node value

#list Settled: All nodes who's shortest path is known

#start: start node
#end: end node

def euclidianHeuristic(node):
    assert isinstance(node, Node)
    
    return sqrt(pow(endNode.name[0] - node.name[0], 2) + pow(endNode.name[1] - node.name[1], 2))


def aStar():
    startNode.g= 0
    startNode.h= 0
    startNode.f= 0
    Frontier= [startNode]
    Settled= []
    bkptr={startNode:None}
    
    while(len(Frontier) != 0):
        #find node in Frontier list with least f= g + h
        #optimize, this sucks
        currNode= Frontier[0]
        for node in Frontier:
            if(node.f < currNode.f):
                currNode= node
        
        Frontier.remove(currNode)
        Settled.append(currNode)
        
        if(currNode == endNode):
            #return shortest path
            shortestPath= [endNode]
            bkptrNode= endNode
            while(bkptr[bkptrNode] != None):
                shortestPath.insert(0, bkptr[bkptrNode])
                bkptrNode= bkptr[bkptrNode]
        
            return shortestPath
        
        
        for edge in currNode.edges:
            neighbor= currNode.getNeighbor(edge)

            tempG= currNode.g + edge.weight
            tempH= euclidianHeuristic(neighbor)
            tempF= tempG + tempH
            
            if((neighbor not in Frontier) and (neighbor not in Settled)):
                Frontier.append(neighbor)
                neighbor.g= tempG
                neighbor.h= tempH
                neighbor.f= tempF

                bkptr[neighbor]= currNode
        
            elif(tempF < neighbor.f):
                neighbor.g= tempG
                neighbor.h= tempH
                neighbor.f= tempF

                bkptr[neighbor]= currNode
            #elif(currNode.f + edge.weight < neighbor.f):#FIX HERE
            #    neighbor.f= currNode.f + edge.weight
            #    #bkptr
            #    bkptr[neighbor]= currNode

#Run aStar
shp= aStar()
for node in shp:
    print(node.name)
