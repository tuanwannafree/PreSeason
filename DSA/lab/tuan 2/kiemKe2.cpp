#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> a;
    vector<string>::iterator iter;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if ( a[s] == NULL) {
            a.push_back(s);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
