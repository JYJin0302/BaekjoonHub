#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n) {
        vector<int> A(n);
        for (auto& i : A) cin >> i;


        for (int i = 1; i < n; i++) A[i] += A[i - 1];
        int tot = A[n - 1];

        for (int i = 0; i < n; i++) A.push_back(A[i] + tot);

        vector<int> p;
        for (int j = 2; j * j <= tot; j++) {
            if (tot % j == 0) {
                if (j > 2 && j <= n) p.push_back(j);
                if (tot / j != j && tot / j <= n) p.push_back(tot / j);
            }
        }
        if (tot >= 3 && tot <= n) p.push_back(tot);

        sort(p.rbegin(), p.rend());

        /* cout << "Tot: " << tot << '\n';
         for (auto k : p) cout << k << ' ';
         cout << '\n';*/

           
        int ans = -1;
        for (auto j : p) {
            if (ans != -1) break;
            // test  i, j

            map<int, int> dp;
            int len = tot / j;

            for (int i = 0; i < n; i++) {
                dp[A[i]] = dp[A[i] - len] + 1;
            }
            bool ok = 0;
            for (int i = n; i < n * 2; i++) {
                if (dp[A[i] - len] == j) {
                    ok = 1;
                    break;
                }
            }

            if (ok) {
                ans = n - j;
                break;
            }
        }

        cout << ans << '\n';

        cin >> n;
    }
}