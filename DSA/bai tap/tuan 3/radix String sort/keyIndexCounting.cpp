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

struct Student {
    string name;
    int key;
};

void sortKey(vector<Student> &a, int r) {
    int n = a.size();
    vector<Student> aux(n);
    vector<int> cnt(r + 1, 0);

    for(int i = 0; i < n; i++) {
        cnt[a[i].key + 1]++;
    }

    for(int i = 0; i < r; i++) {
        cnt[i+1] += cnt[i];
    }

    for(int i =0; i < n ; i++) {
        aux[cnt[a[i].key]++] = a[i];
    }

    for(int i = 0; i < n; i++) {
        a[i] = aux[i];
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Student> students = {
        {"Anderson", 2}, {"Brown", 3}, {"Davis", 3},
        {"Garcia", 4}, {"Harris", 1}, {"Jackson", 3},
        {"Johnson", 4}, {"Jones", 3}, {"Martin", 1},
        {"Martinez", 2}, {"Miller", 2}, {"Moore", 1},
        {"Robinson", 2}, {"Smith", 4}, {"Taylor", 3},
        {"Thomas", 4}, {"Thompson", 4}, {"White", 2},
        {"Williams", 3}, {"Wilson", 4}
    };

    int r = 4;
    sortKey(students, r);

    for (const auto& s : students)
        cout << s.name << " (" << s.key << ")" << endl;

	return 0;
}
