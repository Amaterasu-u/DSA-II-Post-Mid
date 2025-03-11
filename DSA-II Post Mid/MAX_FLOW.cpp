#include <bits/stdc++.h>
using namespace std;

#define V 6
/*
Residual Graph->To find the augmenting path and residual capacity
Main Graph->To flow that residual capacity from the augmenting path in the main graph
*/
bool bfs(int rGraph[V][V], int s, int t, int parent[]) { //BFS for finding augmenting path in the residual graph
    /*
    Takes RESIDUAL Graph as input
    rGraph[V][V]->residuaL GRAPH which holds the current capacity of each edge
    parent array-> to store the path
    */
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            //Adjacency matrix so u vertex er shathe V gula vertex er moddhe kon vertex 
            //er shathe edge ase sheta check kortesi by rGraph[u][v] > 0
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(int graph[V][V], int s, int t) {//it updates the residual graph|| takes the MAIN graph as input
    int u, v;
    int rGraph[V][V];
    
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }
    /*
    A double loop copies the original capacities from graph to rGraph.
     Initially, the residual graph is identical to the original graph.
    */
    
    int parent[V];
    int max_flow = 0;
    /*
    parent[] is declared to store the augmenting path found by BFS.
max_flow is initialized to 0 to accumulate the total flow through the network.
    */

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
/*
This loop backtracks from the sink t to the source s using the parent array.
For each edge on the path, it finds the minimum residual capacity,
 which is the maximum flow that can be sent along this path (the bottleneck).
*/
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    
    int maxFlow = fordFulkerson(graph, 0, 5);
    cout << "The maximum possible flow is " << maxFlow << endl;

}