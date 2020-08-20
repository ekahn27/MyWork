"""
Undirected Graph for A* algorithm
"""
class Node:
    def __init__(self, f= None, edges= None, name= ""):
        self.f= f
        if (edges is None):
            self.edges= []
        else:
            self.edges= edges
        self.name= name

    def getNeighbor(self, edge):
        assert isinstance(edge, Edge)
        return edge.getOppNode(self)

    def add(self, nodeAdd, edgeWeight= 1, edgeName= ""):
        """
        Connect node1 to node2
        """
        assert isinstance(nodeAdd, Node)

        edge= Edge(self, nodeAdd, edgeWeight, edgeName)
        self.edges.append(edge)
        nodeAdd.edges.append(edge)
        return
    
    def remove(self):
        """
        Remove a node from the graph
        """
        assert isinstance(self, Node)

        for edge in self.edges:
            neighbor= getNeighbor(edge)
            neighbor.edges.remove(edge)
        self.edges=[]
        return

    def isNeighbor(self, node):
        """
        Return true if there is already an edge to <node>.
        Return false otherwise
        """
        assert isinstance(node, Node)
        
        for edge in self.edges:
            if(node == edge.getOppNode(self)):
                return True
        return False
        

class Edge:
    def __init__(self, node1, node2, weight, name= ""):
        assert isinstance(node1, Node)
        assert isinstance(node2, Node)

        self.weight= weight
        self.name= name
        self.node1= node1
        self.node2= node2

    def getOppNode(self, node):
        """
        Given a node, return the other node connected to this edge
        """
        assert isinstance(node, Node)
        if(node == self.node1):
            return self.node2
        return self.node1

#Set up graph
"""
0,0  0,1  0,2  0,3  0,4

1,0  1,1  1,2  1,3  1,4

2,0  2,1  2,2  2,3  2,4

3,0  3,1  3,2  3,3  3,4

4,0  4,1  4,2  4,3  4,4
"""
rows= 2
cols= 3
nodes=[[None for i in range(cols)] for j in range(rows)]
#Make nodes and connect them
for row in range(rows):
    for col in range(cols):
        nodes[row][col]= Node(name= [row, col])


#Connect Corners
#[0,0], [0, cols-1], [rows-1, 0], [rows-1, cols-1]
if(rows >= 2 and cols >= 2):
    moveRow= -1
    moveCol= -1
    for row in [0, rows-1]:
        moveRow *= -1
        for col in [0, cols -1]:
            moveCol *= -1
            if(not nodes[row][col].isNeighbor(nodes[row+moveRow][col])):
                nodes[row][col].add(nodes[row+moveRow][col])
            if(not nodes[row][col].isNeighbor(nodes[row][col+moveCol])):
                nodes[row][col].add(nodes[row][col+moveCol])
            if(not nodes[row][col].isNeighbor(nodes[row+moveRow][col+moveCol])):
                nodes[row][col].add(nodes[row+moveRow][col+moveCol])

#Connect Edges
#[0,1], ... [0, cols - 2] - Top edge
#[1,0], ... [rows - 2, 0] - Left edge
#[1, cols-1], ... [rows-2, cols-1] - Right edge
#[rows-1, 1], ... [rows-1, cols-2] - Bottom edge
if((rows >=3 and cols >=2) or (rows >=2 and cols >=3)):
    for topEdgeCol in range(1, cols-1):
        for nodeAddPos in [[0,-1], [1,-1], [1,0], [1,1], [0,1]]:
            nodeToAdd= nodes[nodeAddPos[0]][topEdgeCol + nodeAddPos[1]]
            if(not nodes[0][topEdgeCol].isNeighbor(nodeToAdd)):
                nodes[0][topEdgeCol].add(nodeToAdd)

    for leftEdgeRow in range(1, rows-1):
        for nodeAddPos in [[-1,0], [-1,1], [0,1], [1,1], [1,0]]:
            nodeToAdd= nodes[leftEdgeRow + nodeAddPos[0]][nodeAddPos[1]]
            if(not nodes[leftEdgeRow][0].isNeighbor(nodeToAdd)):
                nodes[leftEdgeRow][0].add(nodeToAdd)

    for rightEdgeRow in range(1, rows-1):
        for nodeAddPos in [[-1,0], [-1,-1], [0,-1], [1,-1], [1,0]]:
            nodeToAdd= nodes[rightEdgeRow + nodeAddPos[0]][cols-1 + nodeAddPos[1]]
            if(not nodes[rightEdgeRow][cols-1].isNeighbor(nodeToAdd)):
                nodes[rightEdgeRow][cols-1].add(nodeToAdd)

    for botEdgeCol in range(1, cols-1):
        for nodeAddPos in [[0,-1], [-1,-1], [-1,0], [-1,1], [0,1]]:
            nodeToAdd= nodes[rows-1 + nodeAddPos[0]][botEdgeCol + nodeAddPos[1]]
            if(not nodes[rows-1][botEdgeCol].isNeighbor(nodeToAdd)):
                nodes[rows-1][botEdgeCol].add(nodeToAdd)

#Connect Interior
#[1,1] ... [1, cols-2]
#[2,1] ... [2, cols-2]
# ...
#[rows-2, 1] ... [rows-2, cols-2]
if(rows >=3 and cols >= 3):
    for row in range(1, rows-1):
        for col in range(1, cols-1):
            for rowMove in [-1, 0 ,1]:
                for colMove in [-1, 0, 1]:
                    nodeToAdd= nodes[row + rowMove][col + colMove]
                    if((rowMove != 0 or colMove != 0) and (not nodes[row][col].isNeighbor(nodeToAdd))):
                        nodes[row][col].add(nodeToAdd)

#Manually remove any wanted nodes here w/ <node>.remove()

#
for list in nodes:
    for node in list:
        print(node.name)
        print("Number of edges: " + str(len(node.edges)) + "\n")
startNode= None
endNode= None
