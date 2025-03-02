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

const int ASCII_RANGE = 256;
const int M = 15;



struct Computerinformation {
    string name;
    long speed;
    long double price;
};

void toUpper(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}

vector<Computerinformation> aux;


void insertionSort(vector<Computerinformation> &a, int lo, int hi, int d) {
    for(int i = lo; i <= hi ;i++) {
        for(int j = i; j > lo && a[j].name.substr(d) < a[j-1].name.substr(d); j--) {
            swap(a[j], a[j-1]);
        }
    }
}

void MDSSort(vector<Computerinformation> &a, int lo, int hi, int d) {
    if(hi <= lo + M) {
        insertionSort(a, lo, hi, d);
        return;
    }

    vector<int> cnt(ASCII_RANGE + 2, 0);

    for(int i = lo; i <= hi; i++) {
        int c = (d < a[i].name.length()) ? toupper(a[i].name[d]) : -1;
        cnt[c + 2]++;
    }

    for(int r = 0; r < ASCII_RANGE + 1; r++) {
        cnt[r+1] += cnt[r];
    }

    aux.resize(hi - lo + 1);

    for(int i = lo ; i <= hi; i++) {
        int c = (d < a[i].name.length()) ? toupper(a[i].name[d]) : -1;
        aux[cnt[c+1]++] = a[i];
    }

    for(int i = lo; i <= hi; i++) {
        a[i] = aux[i - lo];
    }

    for(int r = 0; r < ASCII_RANGE; r++) {
        MDSSort(a, lo + cnt[r], lo + cnt[r+1] - 1, d + 1 );
    }
}

void sortByName(vector<Computerinformation> &arr) {
    for(auto &comp : arr) {
        toUpper(comp.name);
    }
    int n = arr.size();
    aux.resize(n);
    MDSSort(arr, 0, n - 1, 0);
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

    vector<Computerinformation> arr = {
        {"Apple MacBook Pro", 3200, 2500.50},
        {"Dell XPS", 3000, 1800.75},
        {"ASUS ROG", 4000, 2000.99},
        {"HP Pavilion", 2800, 1400.00},
        {"Lenovo ThinkPad", 3500, 2200.00},
        {"Acer Predator", 3600, 1700.25},
        {"MSI Stealth", 3400, 2100.80},
        {"Samsung Galaxy Book", 2900, 1600.00},
        {"Gigabyte Aorus", 3100, 1900.55},
        {"Razer Blade", 3300, 2300.99}
    };

//	int n; cin >> n;
//	cin.ignore();
//	for(int i = 0; i < n; i++) {
//        Computerinformation a;
//        cin.get(a.name, 100);
//        cin >> a.speed;
//        cin >> a.price;
//        cin.ignore();
//        arr.push_back(a);
//	}

	sortByName(arr);
	display(arr);

	return 0;
}
