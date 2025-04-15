#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    int test = -1;
    int cnt;
    int pos;

    for(int i = 0 ; i < n; i++) {
        if(a[i] == x) {
            test = 1;
            cnt = i +1;
            pos= n - cnt;
        }

    }
    if(test == -1) {
        cout << test;
    }
    else {
        cout << test << endl;
        cout << cnt << endl;
        cout<< pos<< endl;
        cout << pos+1;
    }


	return 0;
}
