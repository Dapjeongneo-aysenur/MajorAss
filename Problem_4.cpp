#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair
struct Pair {
    int first;
    int second;
};

// Comparator function to sort pairs based on their second number in ascending order
bool compare(const Pair& p1, const Pair& p2) {
    return p1.second < p2.second;
}

// Function to find the length of the longest chain of pairs
int maxChainLen(vector<Pair>& pairs) {
    // Sort pairs based on their second number in ascending order
    sort(pairs.begin(), pairs.end(), compare);

    int maxLength = 1; // Initialize the length of the longest chain
    int prevEnd = pairs[0].second; // End of the first pair

    // Iterate through the sorted pairs and count the number of pairs forming the chain
    for (int i = 1; i < pairs.size(); ++i) {
        // If the first number of the current pair is greater than or equal to the end
        // of the previous pair, increment the length of the chain and update the end
        if (pairs[i].first > prevEnd) {
            maxLength++;
            prevEnd = pairs[i].second;
        }
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
