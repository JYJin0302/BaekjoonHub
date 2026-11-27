#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(50) << fixed;

    int n, a;
    cin >> n >> a;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    long double l = 0, r = 1e7, ans = -1;
    while (r - l >= 1e-9) {

        long double m = (l + r) / 2;

        bool valid = 1;

        long double val = a;
        for (int i = 0; i < n; i++) {
            val += m;

            if (floor(val) > A[i]) {
                valid = 0;
                r = m;
                break;
            }
            else if (floor(val) < A[i]) {
                valid = 0;
                l = m;
                break;
            }
        }

        if (valid) {
            ans = m;
            r = m;
        }
    }

    cout << ans;
}