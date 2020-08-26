"""
Undirected Graph
"""
class Node:
    def __init__(self, dist= None, edges= None, name= ""):
        self.dist= dist
        if (edges is None):
            self.edges= []
        else:
            self.edges= edges
        self.name= name

    def getNeighbor(self, edge):
        assert isinstance(edge, Edge)
        return edge.getOppNode(self)

    def add(self, nodeAdd, edgeWeight, edgeName= ""):
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
            neighbor= self.getNeighbor(edge)
            neighbor.edges.remove(edge)

            edge.node1= None
            edge.node2= None

        self.edges=[]
        return

class Edge:
    def __init__(self, node1, node2, weight, name= ""):
        assert isinstance(node1, Node)
        assert isinstance(node2, Node)

        self.weight= weight
        self.name= name
        self.node1= node1
        self.node2= node2

    def getOppNode(self, node):
        assert isinstance(node, Node)
        if(node == self.node1):
            return self.node2
        return self.node1

#Set up graph
node1= Node(name="One")
node2= Node(name="Two")
node3= Node(name="Three")
node4= Node(name="Four") 

node1.add(node2, 3, "edgey")
node1.add(node3, 4, "edgey2")
node3.add(node4, 1, "link")
node2.add(node4, 3, "link2")

#    print("Node1: " + node1.name)
#    for edge in node1.edges:
#        print("Edge: " + edge.name + " Weight: " + str(edge.weight))
#
#    print("Node2: " + node2.name)
#    for edge in node2.edges:
#        print("Edge: " + edge.name + " Weight: " + str(edge.weight))
#
#    print("Node3: " + node3.name)
#    for edge in node3.edges:
#        print("Edge: " + edge.name + " Weight: " + str(edge.weight))

startNode= node1
endNode= node4
