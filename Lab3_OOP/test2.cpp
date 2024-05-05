#include <iostream>
#include <vector> 

using namespace std;

int main() {
    int n, max, step, k, count = 0;
    cin >> n >> k;

    int *dynamic, *way, *arr;
    vector<int> currentWay; 

    dynamic = new int[n];
    way = new int[n];
    arr = new int[n];

    for (int i = 1; i < n - 1; ++i) {
        cin >> arr[i];
    }

    dynamic[0] = arr[0] = 0;
    arr[n - 1] = 0;
    way[0] = 0;

    for (int i = 1; i < n; ++i) {
        max = INT_MIN;
        for (int j = 1; j <= k && j <= i; ++j) {
            if (max < dynamic[i - j]) {
                max = dynamic[i - j];
                step = j;
            }
        }

        count++;
        way[i] = step;
        dynamic[i] = arr[i] + max;
    }

    cout << dynamic[n - 1] << endl;
    int iterations = 0;

    for (int i = n - 1; i > 0 && iterations < n; i = way[i]) {
    currentWay.push_back(way[i]);
    iterations++;
}

    for (int i = currentWay.size() - 1; i > -1; --i) {
        if (currentWay[i])
            cout << currentWay[i] << endl;
    }

    cout<<count<<endl;

    delete[] dynamic;
    delete[] way;
    delete[] arr;

    return 0;
}