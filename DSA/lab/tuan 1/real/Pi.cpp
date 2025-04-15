
#include <iostream>
#include <vector>
using namespace std;


void init(vector<int> &a, int n) {
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
}

bool test(vector<int> a, vector<int> b, int m) {
    int sale = 0, buy = 0;
    for(int i = 0; i < a.size(); i++) {
        if(m >= a[i]) {
            sale++;
        }
    }
    for(int i = 0; i < b.size(); i++) {
        if(m <= b[i]) {
            buy++;
        }
    }
    return (sale >= buy);
}

void solve(vector<int> a, vector<int> b) {
    int l = 1, r = 1e9;
    while(l <= r) {
        int m = (l + r) >> 1;
        if((test(a,b,m))) {
            r = m  - 1;
        }
        else {
            l = m +1;
        }
    }
    cout << l;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a;
    vector<int> b;
    init(a, n);
    init(b, m);
    solve(a, b);

	return 0;
}
