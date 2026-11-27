#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool chk[26][26];


vector<int> getz(string S) {
    int N = S.length();
    vector<int> z(N);
    int l, r; l = r = 0;
    for (int i = 1; i < N; i++) {
        if (i <= r) { z[i] = min(r - i + 1, z[i - l]); }
        while (i + z[i] < N && S[z[i]] == S[i + z[i]]) { ++z[i]; }
        if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
    }
    return z;
}

void solve() {

    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    string s;
    cin >> s;

    int sn = s.size();

    for (int i = 0; i < n; i++) {
        int v = s1[i] - 'a';
        int v2 = s2[i] - 'a';
        chk[v][v2] = 1;
    }

    vector<int> A = getz(s);
   // for (auto f : A) cout << f << ' ';

    vector<ll> dp(sn + 1, -1);
    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(0, 0));

    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();

        if (dp[b] != -1) continue;
        dp[b] = -a;

        if (b == sn - 1) {
            cout <<  -a + 1 << '\n';
            return;
        }
        if (b && dp[b - 1] == -1) {
            pq.push(mp(a - 1, b - 1));
        }

        int cur = s[b] - 'a';
        for (int i = 0; i < 26; i++) {
            if (chk[cur][i]) {
                // double
                int len = A[b + 1];
                len = min(len, (int)b + 1);

                int tar = b + len;
                int tlen = b * 2 + 1;

                ll nd = tlen - tar;
                if (tar + 1 < sn && tar == tlen && s[tar + 1] == char('a' + i)) {
                    if (dp[tar + 1] == -1) {
                        pq.push(mp(a - 1, tar + 1));
                    }
                }
                else {
                    if (dp[tar] == -1) {
                        pq.push(mp(a - 2 - nd, tar));
                    }
                }
            }
            else {
                if (dp[b+1] == -1 && s[b + 1] == 'a' + i) {
                    pq.push(mp(a - 1, b + 1));
                }
            }
           

        }

    }
    cout << -1;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}