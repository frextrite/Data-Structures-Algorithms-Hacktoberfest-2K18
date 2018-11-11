#include <iostream>
#include <vector>
#include <list>
#include <queue>

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
    void BFS(int);
    void DFS(int);
    void DFSUtil(int, vector<bool>&);
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void Graph::BFS(int s) {
    vector<bool> visited;
    visited.assign(V, false);

    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        s = q.front();
        list<int>::iterator i;
        for(auto i: adj[s]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        cout << s << " ";
        q.pop();
    }
    cout << "\n";
}

void Graph::DFSUtil(int s, vector<bool> &visited) {
    visited[s] = true;
    cout << s << " ";

    for(auto i : adj[s]) {
        if(!visited[i])
            DFSUtil(i, visited);
    }

    return;
}

void Graph::DFS(int s) {
    vector<bool> visited;
    visited.assign(V, false);

    DFSUtil(s, visited);

    cout << "\n";
}

int main() {
    Graph G(6);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    // G.addEdge(1, 4);
    G.addEdge(2, 4);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(4, 5);
    // G.BFS(0);
    G.addEdge(4, 1);
    G.DFS(0);
    return 0;
}