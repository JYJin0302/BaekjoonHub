#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool isP[505050];
ll dp[505050];

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        if (B.empty() || B.back().first != A[i]) B.push_back(mp(A[i], 1));
        else B.back().second++;
    }

    for (int i = 2; i <= 500000; i++) {
        if (isP[i]) continue;
        for (int j = i * 2; j <= 500000; j+= i) {
            isP[j] = 1;
        }
    }

    ll zc = 0;
    dp[0] = 1;
    for (int i = 0; i < B.size(); i++) {
        int x = B[i].first, cnt = B[i].second;
        if (x == 0) {
            zc = cnt;
            continue;
        }

        for (int j = 500000; j >= x; j--) {
            for (int k = 1; k <= cnt && j - x*k >= 0; k++) {
                dp[j] += dp[j - x * k];
            }
        }
    }

    ll ans = 0;
    for (int i = 2; i <= 500000; i++) {
        if (!isP[i]) ans += dp[i];
    }
    cout << ans * (zc + 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}