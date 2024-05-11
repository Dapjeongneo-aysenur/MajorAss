#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to color a vertex with a given color
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive function to color the graph vertices
bool graphColoringUtil(int v, int M, vector<vector<int>>& graph, vector<int>& color) {
    // Base case: If all vertices are colored, return true
    if (v == graph.size())
        return true;

    // Try all colors for the current vertex
    for (int c = 1; c <= M; ++c) {
        // Check if it's safe to color the vertex with color c
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            // Recur for the next vertex
            if (graphColoringUtil(v + 1, M, graph, color))
                return true;

            // Backtrack: If coloring with color c doesn't lead to a solution, try other colors
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

// Function to check if the graph can be colored with at most M colors
bool graphColoring(int N, int M, vector<vector<int>>& graph) {
    // Create a vector to store the colors assigned to each vertex
    vector<int> color(N, 0);

    // Start coloring from vertex 0
    if (graphColoringUtil(0, M, graph, color))
        return true;
    else
        return false;
}

int main() {
    int N1 = 4, M1 = 3;
    vector<vector<int>> graph1 = { {0, 1, 0, 0},
                                   {1, 0, 1, 0},
                                   {0, 1, 0, 1},
                                   {0, 0, 1, 0} };
    if (graphColoring(N1, M1, graph1))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    int N2 = 3, M2 = 2;
    vector<vector<int>> graph2 = { {0, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 0} };
    if (graphColoring(N2, M2, graph2))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
