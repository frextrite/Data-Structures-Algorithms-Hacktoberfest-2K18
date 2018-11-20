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
    bool isCyclicHelper(int, vector<bool>&, vector<bool>&);
    bool isCyclic();
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool Graph::isCyclicHelper(int u, vector<bool> &visited, vector<bool> &recStack) {
    visited[u] = true;
    recStack[u] = true;

    for(auto i : adj[u]) {
        if(recStack[i])
            return true;

        if(!visited[i])
            if(isCyclicHelper(i, visited, recStack))
                return true;
    }

    recStack[u] = false;
    return false;
}

bool Graph::isCyclic() {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i])
            if(isCyclicHelper(i, visited, recStack)) {
                return true;
            }
    }

    return false;
}

int main() {
    Graph G(6);
    G.addEdge(5, 0);
    G.addEdge(5, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 1);
    G.addEdge(4, 0);
    G.addEdge(4, 1);
    // Graph G(4);
    // G.addEdge(1, 3);
    // G.addEdge(3, 1);
    // G.addEdge(1, 0);
    // G.addEdge(0, 3);
    // G.addEdge(3, 2);
    if(!G.isCyclic()) {
        cout << "Given graph is a DAG\n";
    } else {
        cout << "The given graph contains a cycle\n";
    }
    return 0;
}