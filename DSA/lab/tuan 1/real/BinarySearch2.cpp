#include <algorithm>

#include <ctime>

#include <iostream>

#include <string>


using namespace std;

int cnt = 0;

int binSearch(string a[], string x, int n) {

    int l = 0, r = n -1, m;
    while( l <= r) {
        cnt++;
         m = l + (r-l) / 2;
        if((a[m]) == x) {
            return m;
        }
        else if((a[m]) < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    string arr[2005];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string x; cin >> x;

    int res = binSearch(arr, x, n);

    if(res != -1 ) {
        cout << res <<endl;
        cout << cnt;
    }
    else {
        cout << res;
    }

	return 0;
}
