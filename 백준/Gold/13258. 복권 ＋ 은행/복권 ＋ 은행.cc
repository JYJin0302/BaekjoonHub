#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;

    int n;
    cin >> n;

    vector<int> A(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) A[0] = x;
        else A[1] += x;
    }

    int j, c;
    cin >> j >> c;

    long double x, y, z, tx;

    x = A[0], y = A[1], z = A[0] + A[1];

    while (c--) {
        tx = (x + j) * x / z + x * y / z;
        z += j;
        x = tx, y = z - x;
    }
    cout << x;
}