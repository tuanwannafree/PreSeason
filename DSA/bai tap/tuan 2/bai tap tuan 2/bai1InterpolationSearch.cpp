#include <iostream>
using namespace std;

int solve(int A[], int n, int x) {
    int l = 0, r = n -1, m;
    while(l <= r) {
        m = l + (r-l)*(x-A[l])/(A[r] - A[l]);
        if( x == A[m]) return m;
        if(x < A[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main()
{
    int A[] = {1,2,3,4,5,6,100000};
	int n = 7;
	int x; cin >> x;
	cout << solve(A, 7,x);
	return 0;
}
