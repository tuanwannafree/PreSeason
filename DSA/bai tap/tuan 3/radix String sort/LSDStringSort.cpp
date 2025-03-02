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

void usingLSDSort(vector<string> &a, int w) {
    int n = a.size();
    int R = 256;
    vector<string> aux(n);

    for(int d = w - 1; d >= 0; d--) {
        vector<int> cnt(R + 1, 0);

        for(int i = 0; i < n; i++) {
            cnt[a[i][d] + 1]++;
        }

        for(int r = 0; r < R; r++) {
            cnt[r+1] += cnt[r];
        }
        for(int i = 0; i < n; i++) {
            aux[cnt[a[i][d]]++] = a[i];
        }

        for(int i = 0; i < n; i++) {
            a[i] = aux[i];
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> arr = {
        "4PGC938", "2IYE230", "3CI0720", "1ICK750",
        "10HV845", "3ATW723", "2RLA629", "1ICK750"
    };

    int n = arr[0].size();
    usingLSDSort(arr, n);

    cout << "Sorted strings:\n";
    for (const auto& str : arr)
        cout << str << endl;


	return 0;
}
