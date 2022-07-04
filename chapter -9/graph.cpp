#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int source, dest;
};

class Graph{
public:
    vector<vector<int>> adj;

    Graph(vector<Edge> const &edges, int num){
        adj.resize(num);

        for (auto &edge: edges){
            adj[edge.source].push_back(edge.dest);
        }
    }
};

void Display_Graph(Graph const &G, int num){
    for (int i = 0; i < num; i++){

        cout << i << " -> ";

        for (int v: G.adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<Edge> edges ={
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {4, 6}};
int num = 5;
Graph G(edges,num);

Display_Graph(G,num);

    return 0;
}

