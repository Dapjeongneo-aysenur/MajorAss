#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a given cell is valid to move to
bool isValidMove(int x, int y, int N, vector<vector<int>>& m, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && m[x][y] == 1 && !visited[x][y]);
}

// Function to recursively explore all possible paths from (x, y) to (N-1, N-1)
void explorePaths(int x, int y, int N, vector<vector<int>>& m, vector<vector<bool>>& visited, string path, vector<string>& paths) {
    // Base case: If the current cell is the destination, add the current path to the list of paths
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Define the possible moves (up, down, left, right)
    vector<pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector<char> directions = { 'U', 'D', 'L', 'R' };

    // Explore all possible moves from the current cell
    for (int i = 0; i < moves.size(); ++i) {
        int newX = x + moves[i].first;
        int newY = y + moves[i].second;
        char direction = directions[i];

        // If the move is valid, recursively explore further
        if (isValidMove(newX, newY, N, m, visited)) {
            explorePaths(newX, newY, N, m, visited, path + direction, paths);
        }
    }

    // Backtrack: Mark the current cell as unvisited
    visited[x][y] = false;
}

// Function to find all possible paths from (0, 0) to (N-1, N-1)
vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<string> paths;
    // Check if the starting or destination cell is blocked
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0)
        return paths;

    // Create a matrix to keep track of visited cells
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // Explore all possible paths starting from (0, 0)
    explorePaths(0, 0, N, m, visited, "", paths);

    // Sort the paths lexicographically
    sort(paths.begin(), paths.end());

    return paths;
}

int main() {
    int N1 = 4;
    vector<vector<int>> m1 = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<string> paths1 = printPath(N1, m1);
    if (paths1.empty())
        cout << -1 << endl;
    else {
        for (string path : paths1)
            cout << path << " ";
        cout << endl;
    }

    int N2 = 2;
    vector<vector<int>> m2 = { {1, 0}, {1, 0} };
    vector<string> paths2 = printPath(N2, m2);
    if (paths2.empty())
        cout << -1 << endl;
    else {
        for (string path : paths2)
            cout << path << " ";
        cout << endl;
    }

    return 0;
}
