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

class MSDSort {
    private:
        const int R = 256;
        const int M = 15;
        vector<string> aux;

        int charAt(const string& s, int d) {
            return (d < s.length() ? s[d] : -1);
        }

        void Sort(vector<string> &a, int lo, int hi, int d) {
            if(hi <= lo + M) {
                insertionSort(a, lo, hi, d);
                return;
            }


            vector<int> cnt(R + 2, 0);

            for(int i = lo; i <= hi; i++) {
                cnt[charAt(a[i], d) + 2]++;
            }

            for(int r = 0; r < R; r++ ) {
                cnt[r+1] += cnt[r];
            }

            aux.resize(hi - lo + 1);

            for(int i = lo; i <= hi; i++) {
                aux[cnt[charAt(a[i], d) + 1]++] = a[i];
            }

            for(int i = lo; i <= hi; i++) {
                a[i] = aux[i - lo];
            }
            for(int r = 0; r < R; r++) {
                Sort(a, lo + cnt[r], lo + cnt[r+1]-1, d + 1);
            }
        }
        void insertionSort(vector<string> &a, int lo, int hi, int d) {
            for(int i = lo; i <= hi; i++) {
                for(int j = i ; j > lo && a[j].substr(d) < a[j-1].substr(d); j--) {
                    swap(a[j], a[j-1]);
                }
            }
        }

        public:
            void Sort(vector<string> &a) {
                int N = a.size();
                aux.resize(N);
                Sort(a, 0, N - 1, 0);
            }
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> arr = {
        "4PGC938", "2IYE230", "3CI0720", "1ICK750",
        "10HV845", "3ATW723", "2RLA629", "1ICK750",
        "A", "AB", "ABC", "ABCD", "ABCE"
    };

    MSDSort msdSorter;
    msdSorter.Sort(arr);

    cout << "Sorted strings:\n";
    for (const auto& str : arr)
        cout << str << endl;





	return 0;
}
