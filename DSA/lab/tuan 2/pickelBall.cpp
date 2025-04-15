#include <iostream>
#include <vector>

using namespace std;

const int MAXN= 200;

double getMed(vector<int>& fre, int d) {
    int cnt= 0, med1 = -1, med2 = -1;
    int mid1 = d / 2, mid2 = (d % 2 == 0) ? mid1 - 1 : mid1;

    for (int i = 0; i <= MAXN; i++) {
        cnt += fre[i];

        if (med1 == -1 && cnt > mid2) med1 = i;
        if (cnt > mid1) {
            med2 = i;
            break;
        }
    }

    return (d % 2 == 0) ? (med1 + med2) / 2.0 : med2;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> fre(MAXN + 1, 0);

    for (int i = 0; i < d; i++) fre[a[i]]++;

    int res = 0;
    for (int i = d; i < n; i++) {
        double med = getMed(fre, d);

        if (a[i] >= 2 * med) res++;

        fre[a[i - d]]--;
        fre[a[i]]++;
    }

    cout << res << endl;
    return 0;
}
