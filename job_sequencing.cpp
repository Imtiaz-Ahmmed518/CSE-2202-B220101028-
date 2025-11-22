#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};


bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    cout << "Enter job id, deadline and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    char result[maxDeadline + 1];
    bool slot[maxDeadline + 1];

    for (int i = 1; i <= maxDeadline; i++)
        slot[i] = false;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }


    cout << "\nSelected jobs in order of execution:\n";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }

    cout << "\nTotal Profit = " << totalProfit << endl;

    return 0;
}
