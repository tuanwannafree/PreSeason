#include <iostream>
using namespace std;

int solve(int A[7], int n, int x) {
    int i = 0;
    while(i < n) {
        if(A[i] == x) return i;
        i++;
    }
    return -1;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	int A[] = {1,2,3,4,5,6,100000};
	int n = 7;
	int x; cin >> x;
	cout << solve(A, 7,x);
	return 0;
}
