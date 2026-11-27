#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int dp[1 << 16];
int cap[1 << 16];
int val[1 << 16];

void solve() {

    memset(dp, -1, sizeof(dp));

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    for (auto i : A) {
        if (i > m) {
            cout << 0;
            return;
        }
    }

    vector<int> B;
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] >= i) cnt++;
            else {
                if (cnt) B.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt) B.push_back(cnt);
    }

    if (B.size() > m) {
        cout << 0;
        return;
    }

    vector<pair<int, int>> C(m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        C[i] = mp(a, b);
    }

    int sz = B.size();
    vector<int> sB = { 0 };
    for (int i = 0; i < sz; i++) sB.push_back(sB.back() + B[i]);

    for (int i = 1; i < (1 << m); i++) {
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                cap[i] += C[j].first;
                val[i] += C[j].second;
            }
        }
    }

    dp[0] = 0;
    for (int i = 1; i < (1 << m); i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) v.push_back(j);
        }

        for (auto f : v) {
            int ni = i ^ (1 << f);
            if (dp[ni] == -1) continue;

            int cp = cap[ni];
            int ix = lower_bound(sB.begin(), sB.end(), cp + 1) - sB.begin();

            if (ix == sB.size()) continue;

            if (sB[ix] >= C[f].first + cap[ni]) {
                dp[i] = max(dp[i], dp[ni] + C[f].second);
            }
        }
    }

    int totCap = sB.back();
    int ans = -1;
    for (int i = 0; i < (1 << m); i++) {
        if (cap[i] == totCap) ans = max(ans, dp[i]);
    }
    if (ans == -1) ans = 0;
    cout << ans;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
