// Check if given Directed Graph is acyclic or not

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int, int);
    void DFSVISIT(int, vector<bool>&, stack<int>&);
    void topological(int);
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::DFSVISIT(int s, vector<bool> &visited, stack<int> &topologicalStack) {
    visited[s] = true;

    for(auto i : adj[s]) {
        if(!visited[i])
            DFSVISIT(i, visited, topologicalStack);
    }

    topologicalStack.push(s);
}

void Graph::topological(int s) {
    vector<bool> visited(V);
    stack<int> topologicalStack;

    for(int i = 0; i < V; i++) {
        if(!visited[i])
            DFSVISIT(i, visited, topologicalStack);
    }

    while(!topologicalStack.empty()) {
        int x = topologicalStack.top();
        topologicalStack.pop();
        cout << x << " ";
    }

    cout << "\n";
}

int main() {
    Graph G(6);
    G.addEdge(5, 0);
    G.addEdge(5, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 1);
    G.addEdge(4, 0);
    G.addEdge(4, 1);
    G.topological(5);
    return 0;
}