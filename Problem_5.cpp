#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair
struct Pair {
    int first;
    int second;
};

// Comparator function to sort pairs based on their first number in ascending order
bool compare(const Pair& p1, const Pair& p2) {
    return p1.first < p2.first;
}

// Function to find the length of the longest chain of pairs using dynamic programming
int maxChainLen(vector<Pair>& pairs) {
    // Sort pairs based on their first number in ascending order
    sort(pairs.begin(), pairs.end(), compare);

    int n = pairs.size();
    // Initialize a table to store the length of the longest chain ending at each pair
    vector<int> dp(n, 1);

    // Iterate through pairs and update the table
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // If the second number of the current pair is less than the first number of
            // the previous pair, update the length of the longest chain ending at the current pair
            if (pairs[i].first > pairs[j].second && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    // Find the maximum length in the table
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > maxLength)
            maxLength = dp[i];
    }

    return maxLength;
}

int main() {
    vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << "Length of the longest chain: " << maxChainLen(pairs1) << endl;

    vector<Pair> pairs2 = { {5, 10}, {1, 11} };
    cout << "Length of the longest chain: " << maxChainLen(pairs2) << endl;

    return 0;
}
