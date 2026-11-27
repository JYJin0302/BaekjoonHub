#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()

vector<int> operator+(const vector<int>& v1, const vector<int>& v2) {
    vector<int> res(9);
    for (int i = 0; i < 9; i++) res[i] = v1[i] + v2[i];
    return res;
}

vector<int> G[5];
vector<vector<int>> S[22];

void uniq(vector<vector<int>>& s) {
    sort(all(s));
    s.erase(unique(all(s)), s.end());
}

vector<vector<int>> sP;
vector<int> setF(const vector<int>& v) {
    vector<int> res(9);
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j <= i; j++) {
            if (v[i] == v[j]) {
                res[i] = j;
                break;
            }
        }
    }
    return res;
}

int cntS[22][11];
int merg[11][11];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    G[0] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    G[1] = { 1, 2, 0, 0, 1, 2, 2, 0, 1 };
    G[2] = { 2, 0, 1, 0, 1, 2, 1, 2, 0 };
    G[3] = { 1, 0, 2, 2, 1, 0, 0, 2, 1 };
    G[4] = { 0, 2, 1, 2, 1, 0, 1, 0, 2 };

    S[0].push_back(vector<int>(9));
    for (int i = 1; i <= 20; i++) {
        for (auto pre : S[i - 1]) {
            for (int j = 0; j < 5; j++) {
                S[i].push_back(pre + G[j]);
            }
        }
        uniq(S[i]);

        for (auto f : S[i]) {
            vector<int> res = setF(f);
            if (find(all(sP), res) == sP.end()) sP.push_back(res);
        }
    }

    /*for (auto f : sP) {
        for (auto k : f) cout << k << ' ';
        cout << '\n';
    }*/

    for (int i = 1; i <= 20; i++) {
        for (auto f : S[i]) {
            vector<int> res = setF(f);
            int ix = find(all(sP), res) - sP.begin();
            if (ix >= 0 && ix < 10) cntS[i][ix]++;
        }

        //for (int j = 0; j < 10; j++) cout << cnt[i][j] << ' ';
        //cout << '\n';
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            vector<int> v1 = sP[i], v2 = sP[j];

            vector<int> res(9);
            for (int k = 1; k < 9; k++) {
                for (int f = 0; f <= k; f++) {
                    if (v1[k] == v1[f] && v2[k] == v2[f]) {
                        res[k] = f;
                        break;
                    }
                }
            }

            res = setF(res);
            int ix = find(all(sP), res) - sP.begin();
            merg[i][j] = ix;
        }
    }

    vector<int> nxt(1001010, -1);
    for (int i = 2; i <= 1000000; i++) {
        if (nxt[i] != -1) continue;
        for (int j = i; j <= 1000000; j += i) {
            if (nxt[j] == -1) nxt[j] = i;
        }
    }

    vector<ll> ans(1001010);
    for (int i = 2; i <= 1000000; i++) {

        vector<int> p;
        int cur = i;
        while (cur != 1) {
            p.push_back(nxt[cur]);
            cur /= nxt[cur];
        }
        sort(all(p));

        vector<int> np;
        cur = p[0];
        int cnt = 0;
        for (auto f : p) {
            if (f == cur) cnt++;
            else {
                np.push_back(cnt);
                cur = f;
                cnt = 1;
            }
        }
        np.push_back(cnt);

        vector<ll> dp(10);
        for (int f = 0; f < 10; f++) dp[f] = cntS[np[0]][f];

        for (int f = 1; f < np.size(); f++) {
            vector<ll> tmp(10);
            for (int k = 0; k < 10; k++) tmp[k] = cntS[np[f]][k];

            vector<ll> ndp(10);

            for (int u = 0; u < 10; u++) {
                for (int v = 0; v < 10; v++) {
                    ndp[merg[u][v]] += dp[u] * tmp[v];
                }
            }
            dp = ndp;
        }

        ans[i] = dp[9] + ans[i-1];
    }

    int t;
    cin >> t;
    while (t--) {

        ll n;
        cin >> n;

        ll l = 1, r = 1000000, res = -1;
        while (l <= r) {
            ll md = (l + r) >> 1;
            if (md * md * md <= n) {
                res = md;
                l = md + 1;
            }
            else r = md - 1;
        }

        cout << ans[res] << '\n';
    }
    return 0;
}