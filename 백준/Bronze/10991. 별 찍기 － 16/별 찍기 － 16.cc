#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string b(n - i, ' ');
        cout << b;
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << '\n';
    }


}