#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;


    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;


    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArray(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int max_left = maxSubArray(arr, left, mid);
    int max_right = maxSubArray(arr, mid + 1, right);
    int max_cross = maxCrossingSum(arr, left, mid, right);

    return max(max_left, max(max_right, max_cross));
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArray(arr, 0, size - 1);
    cout << "Maximum Subarray Sum is: " << maxSum << endl;

    return 0;
}

