#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string b(n - i, ' ');
        cout << b;
        if (i != 1 && i != n) {
            string b1(2 * i - 3, ' ');
            cout << "*" + b1 + '*';
        }
        else {
            string st(2*i - 1, '*');
            cout << st;
        }
        cout << '\n';
    }



}