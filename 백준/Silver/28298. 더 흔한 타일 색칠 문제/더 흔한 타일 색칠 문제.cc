#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    int res = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            vector<int> cnt(26);
            for (int ti = i; ti < n; ti += k) {
                for (int tj = j; tj < m; tj += k) {
                    cnt[A[ti][tj] - 'A']++;
                }
            }

            int tx = max_element(cnt.begin(), cnt.end()) - cnt.begin();

            for (int ti = i; ti < n; ti += k) {
                for (int tj = j; tj < m; tj += k) {
                    if ((A[ti][tj] - 'A') != tx) {
                        A[ti][tj] = char('A' + tx);
                        res++;
                    }
                }
            }

        }
    }

    cout << res << '\n';
    for (auto i : A) cout << i << '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}