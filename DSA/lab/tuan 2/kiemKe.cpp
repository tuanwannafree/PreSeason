#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct mang {
    string a;
    int b;
};

bool check(const mang &x, const mang &y) {
    if (x.a != y.a) return x.a < y.a;
    return x.b > y.b;
}

int partition(vector<mang> &arr, int low, int high) {
    mang pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (check(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<mang> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, 0, n - 1);

    vector<mang> arr;
    string current = input[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (input[i] == current) {
            count++;
        } else {
            arr.push_back({current, count});
            current = input[i];
            count = 1;
        }
    }
    arr.push_back({current, count});

    quickSort(arr, 0, arr.size() - 1);

    for (auto &x : arr) {
        cout << x.a << " " << x.b << "\n";
    }

    return 0;
}
