#include <bits/stdc++.h>
using namespace std;

int GCD(int n, int m) {
    if (n < m) swap(n, m);
    if (m == 0) return n;
    return GCD(m, n % m);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> base(n);
    for (auto& i : base) cin >> i;

    int b = 0;
    for (int i = 1; i <= n - 1; i++) {
        b = GCD(b, base[i] - base[i - 1]);
    }

    cout << (base[n - 1] - base[0]) / b - n + 1;

}