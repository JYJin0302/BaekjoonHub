#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 0x3f3f3f3f;
int dp[555][1 << 7];
// dp[i][msk] : i번째까지 확인, i-m+1 부터 i개의 상태 = msk 일 때의 1의 최소 개수
int from[555][1 << 7];

string pf(int x) {
    string res;
    for (int j = 0; j < 7; j++) {
        if (x & (1 << j)) res += '1';
        else res += '0';
    }
    return res;
}
void solve() {

    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    reverse(all(s2));

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (dp[i - 1][j] == INF) continue;
           // cout << i-1 << " " << pf(j) << " = " << dp[i-1][j] << '\n';
            int dif = 0;
            int nmsk = j << 1;
            if (s1[i - 1] == '1') nmsk |= 1, dif++;
            nmsk %= 1 << m;

            if (dp[i][nmsk] > dp[i - 1][j] + dif) {
                dp[i][nmsk] = dp[i - 1][j] + dif;
                from[i][nmsk] = j;
            }

            if (i >= m) {
                // try toggle
                for (int f = 0; f < m; f++) {
                    if (nmsk & (1 << f)) dif--;
                }
                for (int f = 0; f < m; f++) {
                    if (s2[f] == '1') nmsk ^= (1 << f);
                }
                for (int f = 0; f < m; f++) {
                    if (nmsk & (1 << f)) dif++;
                }

                if (dp[i][nmsk] > dp[i - 1][j] + dif) {
                    dp[i][nmsk] = dp[i - 1][j] + dif;
                    from[i][nmsk] = - j -1;
                }
            }
        }
    }

    int ans = n;
    int msk = 0;
    for (int i = 0; i < (1 << m); i++) {
        ans = min(ans, dp[n][i]);
        if (ans == dp[n][i]) msk = i;
    }

    vector<int> res;
    int pos = n;
    while (pos) {
        //cout << pos << ' ' << pf(msk) << '\n';
        int pv = from[pos][msk];

        if (pv < 0) {
            pv = pv * -1 - 1;
            res.push_back(pos - m + 1);
        }
        pos--;
        msk = pv;
    }

    cout << res.size() << '\n';
    for (auto f : res) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}