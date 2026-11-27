#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
string s;
vector<int> ix;
int dp[3][1515][1515];
int L[1515], R[1515];

int getDp(int v1, int l, int r) {
    //cout << "Cal: " << v1 << " " << v2 << ' ' << l << ' ' << r << '\n';
    if (l > r) return dp[v1][l][r] = 0;
    if (dp[v1][l][r] != -1) return dp[v1][l][r];

    if (v1 == 0 && ix[0] != -1) {
        for (int i = 1; i <= 2; i++) if (getDp(i, l, r) == 0) return dp[v1][l][r] = 1;
    }

    if (s[l] != '?' || (ix[0] == l && v1)) {
        int cur = 0;
        if (s[l] != '?') cur = s[l] - '0';
        else cur = v1 - 1;

        int tl = l;
        if (tl + 1 < n && s[tl + 1] - '0' == cur) tl += R[tl + 1];
        if (tl + 1 < n && tl + 1 == ix[0] && v1 && v1 - 1 == cur) tl++;
        if (tl + 1 < n && s[tl + 1] - '0' == cur) tl += R[tl + 1];

        if (tl >= r) {
            return dp[v1][l][r] = 1;
        }

        for (int i = l; i <= tl; i++) {
            if (getDp(v1, i + 1, r) == 0) return dp[v1][l][r] = 1;
        }
    }

    if (s[r] != '?' || (ix[0] == r && v1)) {

        int cur = 0;
        if (s[r] != '?') cur = s[r] - '0';
        else cur = v1 - 1;

        int tl = r;
        if (tl && s[tl - 1] - '0' == cur) tl -= L[tl - 1];
        if (tl && tl - 1 == ix[0] && v1 && v1 - 1 == cur) tl--;
        if (tl && s[tl - 1] - '0' == cur) tl -= L[tl - 1];

        if (tl <= l) {
            return dp[v1][l][r] = 1;
        }

        for (int i = r; i >= tl; i--) {
            if (getDp(v1, l, i - 1) == 0) return dp[v1][l][r] = 1;
        }
    }
    // cout << "NO : " << v1 << ' ' << v2 << ' ' << l << ' ' << r << '\n';
    return dp[v1][l][r] = 0;
}
void solve() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            ix.push_back(i);
        }
    }
    if (ix.empty()) ix.push_back(-1);

    L[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '?' || s[i - 1] != s[i]) L[i] = 1;
        else L[i] = L[i - 1] + 1;
    }
    R[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '?' || s[i + 1] != s[i]) R[i] = 1;
        else R[i] = R[i + 1] + 1;
    }

    int res = getDp(0, 0, n - 1);
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}