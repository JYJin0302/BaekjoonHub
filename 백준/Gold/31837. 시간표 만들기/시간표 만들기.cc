#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct D {
    int c;
    int s, e;
};

int n;
int ans = 0;
vector<D> G[20];

int track[20];

bool chk() {
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        if (track[i] != -1) {
            res.push_back(mp(G[i][track[i]].s, G[i][track[i]].e));
        }
    }
    sort(all(res));

    auto [l, r] = res[0];
    for (int i = 1; i < res.size(); i++) {
        auto [nl, nr] = res[i];
        if (nl < r) return 0;
        l = nl, r = nr;
    }
    ans++;
    return 1;

}
void choose(int ix, int cur = 0) {
    if (cur > 22) return;
    if (ix == n) {
        if (cur != 22) return;
        chk();
        return;
    }

    //cout << "Go j: " << -1 << " => " << G[ix].size() << '\n';
    int len = G[ix].size();
    for (int j = -1; j < len; j++) {
       // cout << "Try : " << j << '\n';
        track[ix] = j;
        choose(ix + 1, cur + (j == -1 ? 0 : G[ix][j].c));
    }
}

void solve() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while (k--) {
            int c, d;
            string s, e;
            cin >> c >> d >> s >> e;

            int vs = 0, ve = 0;
            vs = 600 * s[0] + 60 * s[1] + 10 * s[3] + s[4];
            ve = 600 * e[0] + 60 * e[1] + 10 * e[3] + e[4];

            vs += 1500 * (d - 1);
            ve += 1500 * (d - 1);

            G[i].push_back({ c, vs, ve });
        }
    }

    choose(0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}