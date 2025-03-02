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
#include <cstring>
#include <cctype>
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

void sortByName(vector<Computerinformation> &arr) {
    const int ASCII_RANGE = 256;

    int n = arr.size();

    vector<Computerinformation> temp(n);

    vector<int> cnt(ASCII_RANGE + 1, 0);

    for( const auto& a : arr) {
        char firstChar = toupper(a.name[0]);
        cnt[firstChar + 1]++;
    }

    for(int i = 1; i < ASCII_RANGE; i++) {
        cnt[i] += cnt[i - 1];
    }

    for(const auto& a : arr) {
        char firstChar = toupper(a.name[0]);
        temp[cnt[firstChar]++] = a;
    }

    arr = temp;
}

void display(vector<Computerinformation> arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout <<"Brand : " << arr[i].name << endl;
        cout <<"Toc do chay : " << arr[i].speed << endl;
        cout <<"Gia tien : " << arr[i].price << endl;
	}

}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

	vector<Computerinformation> arr;

	int n; cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
        Computerinformation a;
        cin.get(a.name, 100);
        cin >> a.speed;
        cin >> a.price;
        cin.ignore();
        arr.push_back(a);
	}

	sortByName(arr);
	display(arr);

	return 0;
}
