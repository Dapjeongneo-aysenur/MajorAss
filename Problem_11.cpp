#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if it's possible to allocate books to M students with maxPages pages per student
bool isPossible(vector<int>& pages, int M, int maxPages) {
    int students = 1;
    int pagesAllocated = 0;
    for (int page : pages) {
        if (page > maxPages)
            return false;
        if (pagesAllocated + page > maxPages) {
            students++;
            pagesAllocated = page;
            if (students > M)
                return false;
        }
        else {
            pagesAllocated += page;
        }
    }
    return true;
}

int findPages(int N, int M, vector<int>& A) {
    if (N < M)
        return -1;

    int low = *max_element(A.begin(), A.end()); // Minimum value of the search space
    int high = accumulate(A.begin(), A.end(), 0); // Maximum value of the search space
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(A, M, mid)) {
            result = mid;
            high = mid - 1; // Search in the lower half
        }
        else {
            low = mid + 1; // Search in the upper half
        }
    }

    return result;
}

int main() {
    vector<int> A1 = { 12, 34, 67, 90 };
    int N1 = 4, M1 = 2;
    cout << findPages(N1, M1, A1) << endl;

    vector<int> A2 = { 15, 17, 20 };
    int N2 = 3, M2 = 2;
    cout << findPages(N2, M2, A2) << endl;

    return 0;
}
