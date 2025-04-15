#include <iostream>
#include <vector>
#define MAX_INT 100005
#define ln endl
using namespace std;

struct xy {
    int x, y;
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0 ;i < n; i++) {
        cin >> arr[i];
    }
    int x; cin >> x;
    vector<xy> a;
    int pos = MAX_INT;
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            xy tmp;
            tmp.x = i ;
            tmp.y = i + 1;
            a.push_back(tmp);
        }
    }
    if( pos == MAX_INT) {
        cout << 0;
    }
	else {
        cout << a.size() << endl;
        for(int i = 0 ; i < a.size(); i++) {
            cout << a[i].x << " " <<a[i].y << endl;
        }
	}
	return 0;
}
