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

struct Fraction{
    long numerator, denomitator;
};

void init(Fraction &a, Fraction &b) {
    cout << "Input Fraction a: " << endl;
    cin >> a.numerator >> a.denomitator;
    cout << "Input Fraction b: " << endl;
    cin >> b.numerator >> b.denomitator;
}

void Compare(Fraction a, Fraction b) {
    if(a.numerator * b.denomitator > a.denomitator * b.numerator) {
        cout << a.numerator << "/" <<a.denomitator<< endl;
    }
    else {
        cout << b.numerator << "/" << b.denomitator << endl;
    }
}

int main()
{
    Fraction a, b;
    init(a, b);
    Compare(a ,b);
    return 0;
}
