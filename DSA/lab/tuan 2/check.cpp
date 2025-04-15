#include <bits/stdc++.h>
using namespace std;

// Function to get median from a multiset
double getMedian(multiset<int> &window, int d) {
    auto it = next(window.begin(), d / 2); // Middle iterator
    if (d % 2 == 1) return *it; // Odd case
    return (*it + *prev(it)) / 2.0; // Even case
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> window;
    for (int i = 0; i < d; i++) {
        window.insert(a[i]); // Initialize first window
    }

    int res = 0;
    for (int i = d; i < n; i++) {
        double median = getMedian(window, d);

        // Check if current score is "Pickleball Over Limit"
        if (a[i] >= 2 * median) {
            res++;
        }

        // Slide window: Remove the oldest element and add new element
        window.erase(window.find(a[i - d]));
        window.insert(a[i]);
    }

    cout << res << "\n";
    return 0;
}
