#include <iostream>
using namespace std;
 
int main() {
    int n, max, step, k;
    cin >> n >> k;
    int *dynamic, *way, *currentWay, *arr, currentWaySize;
    dynamic = new int[n];
    way = new int[n];
    currentWay = new int[n];
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
        way[i] = step;
        dynamic[i] = arr[i] + max;
    }
    cout << dynamic[n - 1] << std::endl;
    currentWaySize = 0;

    for (int i = n - 1; i > 0; i = way[i]) {
        currentWay[currentWaySize++] = way[i];
    }

    for (int i = currentWaySize - 1; i > -1; --i) {
        if (currentWay[i])
            cout << currentWay[i] << endl;
    }

    delete[] dynamic;
    delete[] way;
    delete[] arr;
    delete[] currentWay;

    return 0;
}