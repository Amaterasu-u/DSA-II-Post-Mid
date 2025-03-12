#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to color vertex 'v' with color 'c'
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& colors, int c, int V) {
    for (int i = 0; i < V; i++) {
        // If there is an edge from v to i and vertex i is colored with c, then it's not safe
        if (graph[v][i] && colors[i] == c)
            return false;
    }
    return true;
}


bool graphColoringUtil(const vector<vector<int>>& graph, int m, int v, vector<int>& colors, int V) {
    // If all vertices have been assigned a color then return true
    if (v == V)
        return true;
    
    // Try assigning each color from 1 to m to vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c, V)) {
            colors[v] = c;  // Assign color c to vertex v

            // Recursively assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, v + 1, colors, V))
                return true;

            // Backtracking: Remove the color assignment if it leads to a dead end
            colors[v] = 0;
        }
    }
    return false;
}

int main() {
    // Number of vertices in the graph
    int V = 4;

    // Adjacency matrix representation of the graph
    // For example, this graph:
    //   0 -- 1
    //   |  / |
    //   2 -- 3
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };


    int m = 3;

    // colors[i] will hold the color assigned to vertex i. 0 means no color assigned.
    vector<int> colors(V, 0);

    if (!graphColoringUtil(graph, m, 0, colors, V)) {
        cout << "Solution does not exist." << endl;
    } else {
        cout << "Solution exists:\n";
        // Print the color assigned to each vertex
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " ---> Color " << colors[i] << "\n";
        }
    }

}
