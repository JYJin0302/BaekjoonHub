#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

string table[5][5];
vector<string> t2(string s) {
    vector<string> res;
    int ix = 0;
    while (ix < s.size()) {
        int nx = ix;
        string ts;
        while (nx < s.size() && s[nx] != ' ') ts += s[nx++];
        res.push_back(ts);
        ix = nx + 1;
    }
    return res;
}

string ans[100];


void solve() {

    int n;
    cin >> n;

    map<string, int> tmp;
    tmp["Tuesday"] = 0;
    tmp["Thursday"] = 1;
    tmp["Saturday"] = 2;
    for (int i = 0; i < n; i++) {
        string s;
        cin.ignore();
        getline(cin, s);

        string d;
        int x;
        cin >> d >> x;

        int y = tmp[d];
        table[x][y] = s;
    }

    for (int i = 0; i < 100; i++) ans[i] = "|          |          |          |";
    string cc = "+----------+----------+----------+";
    ans[0] = cc;
    int cur = 1;

    for (int i = 1; i <= 4; i++) {
        int mx = cur;
        for (int j = 0; j < 3; j++) {
            string s = table[i][j];
            if (s == "") continue;
            vector<string> token = t2(s);

            int cx = cur, cy = 1;
            for (auto f : token) {
                if (cy + f.size() - 1 > 10) {
                    cx++;
                    cy = 1;
                }

                for (auto k : f) {
                    ans[cx][cy + 11 * j] = k;
                    cy++;
                }
                cy++;
                mx = max(mx, cx);
            }
        }
        ans[mx + 1] = cc;
        cur = mx + 2;
    }

    for (int i = 0; i < cur; i++) cout << ans[i] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}