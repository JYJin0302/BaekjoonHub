#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dp[101][101];
int getDp(int a, int b) {
    if (dp[a][b] != -1) return dp[a][b];
    if (a * b == 0 || a == b) return -1;
    map<int, int> cnt;
    for (int j = 0; j < a; j++) {
        cnt[getDp(j, b)]++;
    }
    for (int i = 0; i < b; i++) {
        cnt[getDp(a, i)]++;
    }
    for (int i = 1; i <= min(a, b); i++) {
        cnt[getDp(a - i, b - i)]++;
    }

    int res = 0;
    while (cnt[res]) res++;
    return dp[a][b] = res;

}

void solve() {

    int n;
    cin >> n;

    bool ok = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int tmp = getDp(a, b);
        if (tmp == -1) ok = 1;
        res ^= tmp;
    }
    if (res || ok) cout << "Y\n";
    else cout << "N\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int t = 1;
    // cin >> t;
    while (t--) solve();
}