#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int tx, ty;

int getVal(pair<int, int>& p){

    int dp = max(abs(p.first - tx), abs(p.second - ty));

    if (dp == 0) return 0;

    int x, y;
    tie(x, y) = p;
    int res = (2*dp-1) *(2* dp-1);

    if (x == tx - dp) {
        if (y == ty - dp) res += 8 * dp;
        else res += y - (ty - dp);
    }
    else if (y == ty + dp) {
        res += 2 * dp + x - (tx - dp);
    }
    else if (x == tx + dp) {
        res += 4 * dp + ty + dp - y;
    }
    else {
        res += 6 * dp + tx + dp - x;
    }
    return res - 1;

}

vector<int> dp[101][101];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return dp[a.first][a.second] < dp[b.first][b.second];
}

int res[101][101];

void solve() {

    int n, m;
    cin >> m >> n;

    vector<string> grid(n);
    for (auto& i : grid) cin >> i;

    int k = 0;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 'X') {
                pos.push_back(mp(i, j));
                k++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            tx = i, ty = j;
            vector<int> tmp;
            for (int f = 0; f < pos.size(); f++)tmp.push_back(getVal(pos[f]));

            sort(tmp.begin(), tmp.end());

           /* cout << "REs: " << i << ' ' << j << " : ";
            for (auto f : tmp) cout << f << ' ';
            cout << '\n';*/

            dp[i][j] = tmp;
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans.push_back(mp(i, j));
    }

    sort(ans.begin(), ans.end(), cmp);

 //   for (auto f : ans) cout << f.first << ' ' << f.second << '\n';

    int tans = 0;
    for (int i = 1; i < ans.size(); i++) {

        vector<int>& v1 = dp[ans[i - 1].first][ans[i - 1].second];
        vector<int>& v2 = dp[ans[i].first][ans[i].second];

        int tval = 0;
        for (int f = 0; f < k; f++) {
            if (v1[f] != v2[f]) {
                tval = v1[f];
                break;
            }
        }

        res[ans[i - 1].first][ans[i - 1].second] = max(res[ans[i - 1].first][ans[i - 1].second], tval);
        res[ans[i].first][ans[i].second] = max(res[ans[i].first][ans[i].second], tval);
        tans = max(tans, tval);
    }
    long double ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans2 += res[i][j];
        }
    }

    ans2 /= n * m;
    cout << fixed << setprecision(10);
    cout << ans2 << '\n';
    cout << tans << '\n';

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == tans) {

                cout << '(' << j + 1 << "," << n - i << ") ";
            }
        }
    }
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