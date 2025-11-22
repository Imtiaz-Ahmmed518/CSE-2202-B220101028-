#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {

    sort(arr, arr + n, cmp);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {

        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else {

            double fraction = (double)W / arr[i].weight;
            totalValue += arr[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    Item arr[] = { {30,12}, {22, 15}, {100, 20} };
    int W = 100;
    int n = 3;

    cout << "Maximum value in Knapsack = "
         << fractionalKnapsack(W, arr, n);

    return 0;
}

