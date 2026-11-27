#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int dp[5001][5001];

void solve() {

    int n;
    cin >> n;

    vector<int> A(n), cnt(1000001), cnt2(1000001);
    for (auto& i : A) {
        cin >> i;
        cnt[i]++;
    }

    for (int i = 0; i < n; i++) {
        int x = A[i];

        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                cnt2[j]++;
                if (x / j != j) cnt2[x / j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int x = A[i];
        int ans = 0;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                ans += cnt[j];
                if (x / j != j) ans += cnt[x / j];
            }
        }
        ans -= cnt2[x];
        cout << -ans << ' ';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}