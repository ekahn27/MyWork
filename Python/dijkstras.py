from graph import *
#dijkstras implementation

#Graph Frontier: All nodes in Frontier set where shortest known length from
#start to the node is node value

#Graph Settled: All nodes who's shortest path is known

#start: start node
#end: end node

#graph Map: total, unknown graph

def dijkstras():
    startNode.dist= 0
    Frontier= [startNode]
    Settled= []
    bkptr={startNode:None}
    
    while(len(Frontier) != 0):
        print("while loop")
        #find node in Frontier list with shortest distance
        currNode= Frontier[0]
        for node in Frontier:
            if(node.dist < currNode.dist):
                currNode= node
        
        Frontier.remove(currNode)
        Settled.append(currNode)
        
        if(currNode == endNode):
            #return shortest path
            print("Near End")
            shortestPath= [startNode, endNode]
            bkptrNode= endNode
            while(bkptr[bkptrNode] != None):
                shortestPath.insert(1, bkptr[bkptrNode])
                bkptrNode= bkptr[bkptrNode]
        
            print("Path: " + str(shortestPath))
            return shortestPath
        
        
        for edge in currNode.edges:
            neighbor= currNode.getNeighbor(edge)
            
            if((neighbor not in Frontier) and (neighbor not in Settled)):
                neighbor.dist= currNode.dist + edge.weight
                Frontier.append(neighbor)
                #bkptr
                bkptr[neighbor]= currNode
        
            elif(currNode.dist + edge.weight < neighbor.dist):
                neighbor.dist= currNode.dist + edge.weight
                #bkptr
                bkptr[neighbor]= currNode

#Run dijkstras
shp= []
shp= dijkstras()
for node in shp:
    print(node.name)
