#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int deadline;
    int profit;
};

// Comparator function to sort jobs based on their deadlines in non-decreasing order
bool compare(const Job& j1, const Job& j2) {
    return j1.deadline < j2.deadline;
}

// Function to find the number of jobs done and the maximum profit using dynamic programming
vector<int> JobScheduling(vector<pair<int, int>>& jobs) {
    // Create a vector of jobs
    vector<Job> sortedJobs(jobs.size());
    for (int i = 0; i < jobs.size(); ++i) {
        sortedJobs[i].deadline = jobs[i].first;
        sortedJobs[i].profit = jobs[i].second;
    }

    // Sort jobs based on their deadlines in non-decreasing order
    sort(sortedJobs.begin(), sortedJobs.end(), compare);

    // Initialize a table to store maximum profit up to each deadline
    vector<int> dp(sortedJobs.back().deadline + 1, 0);

    // Iterate through the sorted jobs and update the table
    for (int i = 0; i < sortedJobs.size(); ++i) {
        // Traverse the table from right to left to find a slot to schedule the job
        for (int j = sortedJobs[i].deadline; j > 0; --j) {
            // If a slot is available, update the table with the maximum profit
            if (dp[j] == 0) {
                dp[j] = sortedJobs[i].profit;
                break;
            }
        }
    }

    int totalProfit = 0;
    int jobsDone = 0;

    // Calculate the total profit and number of jobs done
    for (int i = 1; i < dp.size(); ++i) {
        totalProfit += dp[i];
        if (dp[i] > 0)
            jobsDone++;
    }

    return { jobsDone, totalProfit };
}

int main() {
    vector<pair<int, int>> jobs1 = { {4, 20}, {1, 10}, {1, 40}, {1, 30} };
    vector<int> result1 = JobScheduling(jobs1);
    cout << "Number of jobs done: " << result1[0] << ", Maximum profit: " << result1[1] << endl;

    vector<pair<int, int>> jobs2 = { {2, 100}, {1, 19}, {2, 27}, {1, 25}, {1, 15} };
    vector<int> result2 = JobScheduling(jobs2);
    cout << "Number of jobs done: " << result2[0] << ", Maximum profit: " << result2[1] << endl;

    return 0;
}
