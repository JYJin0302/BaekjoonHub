#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;


    long double l = 1, r = 10000, ans = -1;
    while (r - l > 1e-6) {
        long double m = (l + r) / 2;

        vector<long double> B(n), sB(n);
        for (int i = 0; i < n; i++) B[i] = A[i] - m;
        sB[0] = B[0];
        for (int i = 1; i < n; i++) sB[i] = sB[i - 1] + B[i];

        long double tot = sB[n - 1];

        bool ok = 0;
        long double tMin = B[0];
        for (int i = 1; i < n - 1; i++) {
            if (sB[i] - tMin >= tot) ok = 1;
            tMin = min(tMin, sB[i]);
        }

        if (ok) {
            ans = m;
            r = m;
        }
        else l = m;

    }

    cout << fixed << setprecision(3);
    cout << ans;
}
