#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n; cin >> n;
    vector<int> a(n);
    int tmp = 30000000;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n- 1; i++) {
        tmp = min(abs(a[i] - a[i+1]), tmp);
    }
    for(int i = 0; i < n -1; i++) {
        if(abs(a[i] - a[i+1]) == tmp) {
            cout << a[i] << " " << a[i+1] << " ";
        }
    }

	return 0;
}
