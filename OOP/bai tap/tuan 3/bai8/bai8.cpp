

#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int minn;
    for (int i = 0; i < n - 1; i++) {
        minn = i;
        bool check = false;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minn]) {
                minn = j;
                check = true;
            }
            swap(a[i], a[minn]);
            if (check) {
                print(a);
            }
        }
    }

    return 0;
}
