#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs based on their profits in non-increasing order
bool compare(const Job& j1, const Job& j2) {
    return j1.profit > j2.profit;
}

// Function to find the number of jobs done and the maximum profit
vector<int> JobScheduling(vector<pair<int, pair<int, int>>>& jobs) {
    // Create a vector of jobs
    vector<Job> sortedJobs(jobs.size());
    for (int i = 0; i < jobs.size(); ++i) {
        sortedJobs[i].id = jobs[i].first;
        sortedJobs[i].deadline = jobs[i].second.first;
        sortedJobs[i].profit = jobs[i].second.second;
    }

    // Sort jobs based on their profits in non-increasing order
    sort(sortedJobs.begin(), sortedJobs.end(), compare);

    int totalProfit = 0;
    int jobsDone = 0;
    vector<bool> slots(sortedJobs.size(), false); // Slots to track job scheduling

    // Iterate through the sorted jobs and schedule them before their deadlines
    for (int i = 0; i < sortedJobs.size(); ++i) {
        for (int j = min(sortedJobs[i].deadline - 1, (int)slots.size() - 1); j >= 0; --j) {
            if (!slots[j]) {
                slots[j] = true;
                totalProfit += sortedJobs[i].profit;
                jobsDone++;
                break;
            }
        }
    }

    return { jobsDone, totalProfit };
}

int main() {
    vector<pair<int, pair<int, int>>> jobs1 = { {1, {4, 20}}, {2, {1, 10}}, {3, {1, 40}}, {4, {1, 30}} };
    vector<int> result1 = JobScheduling(jobs1);
    cout << "Number of jobs done: " << result1[0] << ", Maximum profit: " << result1[1] << endl;

    vector<pair<int, pair<int, int>>> jobs2 = { {1, {2, 100}}, {2, {1, 19}}, {3, {2, 27}}, {4, {1, 25}}, {5, {1, 15}} };
    vector<int> result2 = JobScheduling(jobs2);
    cout << "Number of jobs done: " << result2[0] << ", Maximum profit: " << result2[1] << endl;

    return 0;
}
