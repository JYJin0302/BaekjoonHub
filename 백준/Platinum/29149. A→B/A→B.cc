#include <bits/stdc++.h>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    if (n & 1) {

        if (m == 1) {
            cout << -1;
            return 0;
        }

        cout << m << '\n';
        cout << n << ' ' << n-2 << ' ';

        for (int i = 0; i < m - 2; i++) cout << 3 + i * 2 << ' ';
        return 0;
    }

    cout << m << '\n';
    if (m == 1) {
        cout << n - 1;
        return 0;
    }

    if (m == 2) {
        cout << n-1 << ' ' << 3;
        return 0;
    }

    cout << n << ' ' << n - 2 << ' ' << 1 << ' ';
    for (int i = 0; i < m - 3; i++) {
        cout << 4 + 2 * i << ' ';
    }

}

