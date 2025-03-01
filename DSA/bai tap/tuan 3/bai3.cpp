#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
using namespace std;

struct Computerinformation {
    char name[100];
    long speed;
    long double price;
};

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

	vector<Computerinformation> arr;

	int n; cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
        Computerinformation a;
        cin.get(a.name, 25);
        cin >> a.speed;
        cin >> a.price;
        cin.ignore();
        arr.push_back(a);
	}

	for(int i = 0; i < n; i++) {
        cout <<"Brand : " << arr[i].name << endl;
        cout <<"Toc do chay : " << arr[i].speed << endl;
        cout <<"Gia tien : " << arr[i].price << endl;

	}

	return 0;
}
