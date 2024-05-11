#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    // Initialize a 2D array dp[][] to store the number of sequences
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize dp[i][1] as 1 for all i from 1 to m
    for (int i = 1; i <= m; ++i)
        dp[i][1] = 1;

    // Fill the dp[][] array using dynamic programming
    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            for (int k = 2 * i; k <= m; ++k) {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }

    // Sum up the values in the last column of dp[][] to get the total number of sequences
    int total = 0;
    for (int i = 1; i <= m; ++i)
        total += dp[i][n];

    return total;
}

int main() {
    int m1 = 10, n1 = 4;
    cout << numberSequence(m1, n1) << endl;

    int m2 = 5, n2 = 2;
    cout << numberSequence(m2, n2) << endl;

    return 0;
}
