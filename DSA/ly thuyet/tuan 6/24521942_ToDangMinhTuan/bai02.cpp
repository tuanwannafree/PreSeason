#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ElementType {
    int N;
    char A;
    char B;
    char C;

    ElementType(int n = 0, char a = ' ', char b = ' ', char c = ' ')
        : N(n), A(a), B(b), C(c) {}
};

void Move(ElementType initial_state) {
    stack<ElementType> S;

    S.push(initial_state);

    while (!S.empty()) {
        ElementType Temp = S.top();
        S.pop();

        if (Temp.N == 1) {
            cout << "Chuyen 1 dia tu " << Temp.A << " sang " << Temp.B << endl;
        } else if (Temp.N > 0) {
            S.push(ElementType(Temp.N - 1, Temp.C, Temp.B, Temp.A));
            S.push(ElementType(1, Temp.A, Temp.B, Temp.C));
            S.push(ElementType(Temp.N - 1, Temp.A, Temp.C, Temp.B));
        }
    }
}

int main() {
    int n;
    cout << "Nhap so dia: ";
    cin >> n;

    if (n < 1) {
        cout << "So dia phai lon hon 0." << endl;
        return 1;
    }

    ElementType initialState(n, 'A', 'B', 'C');

    cout << "Cac buoc chuyen dia:" << endl;
    Move(initialState);

    return 0;
}
