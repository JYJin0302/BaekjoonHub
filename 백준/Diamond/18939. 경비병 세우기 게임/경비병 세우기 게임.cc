#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        k = k * 2 - 1;

        if (k >= n && k >= m) cout << "Yuto\n";
        else if (n % 2 == 1 && m % 2 == 1) cout << "Yuto\n";
        else cout << "Platina\n";
    }
}