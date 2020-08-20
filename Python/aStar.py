from graph2 import *
#A* implementation

#list Frontier: All nodes in Frontier set where shortest known length from
#start to the node is node value

#list Settled: All nodes who's shortest path is known

#start: start node
#end: end node

def dijkstras():
    startNode.f= 0
    Frontier= [startNode]
    Settled= []
    bkptr={startNode:None}
    
    while(len(Frontier) != 0):
        #find node in Frontier list with least f= g + h
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
            
            if((neighbor not in Frontier) and (neighbor not in Settled)):
                neighbor.f= currNode.f + edge.weight
                Frontier.append(neighbor)
                #bkptr
                bkptr[neighbor]= currNode
        
            elif(currNode.f + edge.weight < neighbor.f):
                neighbor.f= currNode.f + edge.weight
                #bkptr
                bkptr[neighbor]= currNode

#Run dijkstras
shp= []
shp= dijkstras()
for node in shp:
    print(node.name)
