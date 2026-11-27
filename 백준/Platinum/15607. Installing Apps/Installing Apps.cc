#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

ostream& operator<<(ostream& os, pair<int, int> p1) {
    return os << '{' << p1.first << ' ' << p1.second << '}';
}

bool cmp(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
    return max(p1.x.x, p1.x.y + p2.x.x) < max(p2.x.x, p2.x.y + p1.x.x);
}

int dp[511][11111];
int from[511][11111];

void solve() {

    memset(from, -1, sizeof(from));
    int n, c;
    cin >> n >> c;

    vector<pair<pair<int, int>, int>> A(n);
    for (int i =0 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        A[i] = mp(mp(a, b), i);
    }

    sort(all(A), cmp);
    /*for (auto f : A) cout << f.first << ' ';
    cout << '\n';*/

    for (int i = 0; i < n; i++) {
        auto& [a, b] = A[i].first;
        for (int j = c; j >= b; j--) {
            if (j - b + a <= c) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - b] + 1);
                if (dp[i + 1][j] == dp[i][j - b] + 1) {
                    from[i + 1][j] = j-b;
                }
            }
        }

        for (int j = 0; j <= c; j++) if (dp[i + 1][j] <= dp[i][j]) {
            from[i + 1][j] = -1;
            dp[i + 1][j] = dp[i][j];
        }

       /* for (int j = 0; j <= c; j++) cout << dp[i + 1][j] << ' ';
            ; cout << '\n';*/
    }

    vector<int> ans;
    pair<int, int> ansp = mp(0, 0);
    for (int j = 0; j <= c; j++) {
        ansp = max(ansp, mp(dp[n][j], j));
    }
    int ansi = ansp.second;
    int ix = n;
    while (ix) {
       // cout << ix << ' ' << ansi << ' ' << dp[ix][ansi] << '\n';
        assert(ansi <= c && ansi >= 0);
        if (from[ix][ansi] != -1){
            ans.push_back(A[ix-1].second);
            ansi = from[ix][ansi];
        }
        ix--;
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto f : ans) cout << f+1 << ' ';
    cout << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout << setprecision(5);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}