#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start;
    int end;
    int index;
};

// Comparator function to sort meetings based on their end times
bool compare(const Meeting& m1, const Meeting& m2) {
    return m1.end < m2.end;
}

// Function to find the maximum number of meetings that can be accommodated
int maxMeetings(int start[], int end[], int n) {
    // Create a vector of meetings
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].index = i + 1; // Adding 1-based index
    }

    // Sort meetings based on their end times
    sort(meetings.begin(), meetings.end(), compare);

    int count = 1; // Count of meetings that can be accommodated
    int prevEnd = meetings[0].end; // End time of the first meeting

    // Iterate through the sorted meetings and choose non-overlapping meetings
    for (int i = 1; i < n; ++i) {
        // If the current meeting's start time is greater than or equal to
        // the end time of the previous meeting, it can be accommodated
        if (meetings[i].start >= prevEnd) {
            count++;
            prevEnd = meetings[i].end;
        }
    }

    return count;
}

int main() {
    int N1 = 6;
    int start1[] = { 1, 3, 0, 5, 8, 5 };
    int end1[] = { 2, 4, 6, 7, 9, 9 };

    cout << "Example 1:\nN = 6\nstart[] = { 1,3,0,5,8,5 }\nend[] = { 2,4,6,7,9,9 }\n";
    cout << "Maximum number of meetings: " << maxMeetings(start1, end1, N1) <<"\n" << endl;

    int N2 = 3;
    int start2[] = { 10, 12, 20 };
    int end2[] = { 20, 25, 30 };
    cout << "Example 2:\nN = 3\nstart[]= { 10, 12, 20 }\nend[]= { 20, 25, 30 }\n";
    cout << "Maximum number of meetings: " << maxMeetings(start2, end2, N2) <<"\n" << endl;

    return 0;
}
