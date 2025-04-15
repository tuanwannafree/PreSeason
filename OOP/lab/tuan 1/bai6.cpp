#include<iostream>
#include<vector>
using namespace std;

void nhap(vector<int> &a) {
    for(int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}

bool check(vector<int> a, vector<int> b, int k, int m) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[k+i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Nhap m va n " << endl;
    int m,n; cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    cout << "Nhap mang a " << endl;
    nhap(a);
    cout << "Nhap mang b " << endl;
    nhap(b);
    int cnt = 0;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(check(a,b,i,m)) {
            cnt++;
            res.push_back(i);
        }
    }
    cout << "So lan mang a xuat hien trong b la " << endl;
    cout << cnt << endl;
    if(!res.empty()) {
        cout << "In ra cac vi tri bat dau tim thay " << endl;
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
	return 0;
}
