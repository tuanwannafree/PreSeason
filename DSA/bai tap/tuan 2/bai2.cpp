#include <iostream>
using namespace std;

int solve(int A[], int n, int x) {
    int l = 0, r = n - 1, m;
    while( l <= r) {
        m = r + (l - r) /2;
        if(A[m] == x) {
            return m;
        } else if( A[m] > x) {
            l = m + 1;
        } else {
            r = m  - 1;
        }
    }
    return -1;
}

int main()
{

    int A[] = {10000, 6 , 5, 4, 3 ,2 ,1};
	int x; cin >> x;
	cout << solve(A, 7,x);


	return 0;
}
