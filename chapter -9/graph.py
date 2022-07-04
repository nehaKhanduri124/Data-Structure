class Graph:
    def __init__(self, numOf_Nodes, directed=True):
        self.m_numOf_Nodes = numOf_Nodes
        self.m_directed = directed

    m_ListOf_edges = []


    def Add_edge(self, N1, N2, weight=1):
        self.m_ListOf_edges.append([N1, N2, weight])

        if not self.m_directed:
            self.m_ListOf_edges.append([N1, N2, weight])


    def display_EdgeList(self):
        numOf_edges = len(self.m_ListOf_edges)
        for i in range(numOf_edges):
            print("edge ", i + 1, " ->  ", self.m_ListOf_edges[i])


G = Graph(6)

G.Add_edge(0, 0, 1)
G.Add_edge(0, 0, 4)
G.Add_edge(0, 2, 3)
G.Add_edge(1, 3, 1)
G.Add_edge(1, 4, 10)
G.Add_edge(4, 2, 7)
G.Add_edge(4, 3, 16)

G.display_EdgeList()