#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
            int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0 ;i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if(n == 1) {
            cout << 0;
        }
        if( n == 2) {
            cout << arr[1] - arr[0];
        }
        if(n == 3) {
            cout << arr[2] - arr[0];
        }
        if ( n >= 4) {
            cout << arr[n-1] + arr[n-2] - arr[0] - arr[1];
        }
    }


	return 0;
}
