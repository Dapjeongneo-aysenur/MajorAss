#include <iostream>
#include <vector>

using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size(), m = arr2.size();
    int left = max(0, k - m), right = min(k, n);

    while (left < right) {
        int mid1 = left + (right - left) / 2;
        int mid2 = k - mid1;

        if (arr1[mid1] < arr2[mid2 - 1])
            left = mid1 + 1;
        else
            right = mid1;
    }

    int mid1 = left, mid2 = k - left;
    int val1 = (mid1 >= n) ? INT_MAX : arr1[mid1];
    int val2 = (mid2 >= m) ? INT_MAX : arr2[mid2 - 1];

    return min(val1, val2);
}

int main() {
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k1 = 5;
    cout << kthElement(arr1, arr2, k1) << endl;

    vector<int> arr3 = { 100, 112, 256, 349, 770 };
    vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
    int k2 = 7;
    cout << kthElement(arr3, arr4, k2) << endl;

    return 0;
}
