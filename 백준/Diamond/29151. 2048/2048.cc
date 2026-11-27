#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
vector<vector<ll>> dp[6][66];

vector<string> pList[6];

int target;
vector<string> ans;
void getPattern(int n, string curr) {
    if (n == target) {
        ans.push_back(curr);
        return;
    }

    vector<int> cnt(8);
    for (auto i : curr) cnt[i - 'a']++;

    int ix = 0;
    while (cnt[ix]) ix++;

    for (int j = 0; j <= ix; j++) {

        if (!curr.empty() && curr[n - 1] == char('a' + j)) continue;
        string tmp = curr + char('a' + j);
        getPattern(n + 1, tmp);
    }
}
void init() {
    for (target = 1; target <= 6; target++) {

        getPattern(0, "");
        pList[target - 1] = ans;
        ans.clear();
    }
}

vector<ll> ttmp(10, -1);
vector<int> ck(10);
ll goMatch(int mn, string curr, int idx, string a, string b) {

    if (idx == a.size()) {
        int tcnt = ck[mn];

        ll res = 1;
        for (int f = 0; f < tcnt; f++) {
            res *= (16ll - f - mn);
            res %= mod;
        }

        return res;
    }

    ll res = 0;
    if (ttmp[b[idx] - 'a'] == -1) { // 처음 나오는 종류 (알파벳)
        for (int i = 0; i <= mn; i++) {
            if (i != a[idx] - 'a' && (!ck[i] || i == mn)) {
                // ok
                ttmp[b[idx]-'a'] = i;
                ck[i] ++;
                res += goMatch(mn, curr + char('a' + i), idx + 1, a, b);
                res %= mod;
                ttmp[b[idx]-'a'] = -1;
                ck[i]--;
            }
        }
    }
    else { // 이미 나온 적 있는 알파벳
        if (int(a[idx] - 'a') == ttmp[b[idx] - 'a']) res += 0;
        else res += goMatch(mn, curr + char('a' + ttmp[b[idx] - 'a']), idx + 1, a, b);
    }
    res %= mod;

    if (idx == 0) {
        // cout << "get dp: " << a << ' ' << b << ' ' << " -> " << res << '\n';
          //Sleep(1);
    }
    return res;
}

ll cntPattern(string a, string b) {
    int n = a.size();

    vector<int> cnt(7);
    for (auto i : a) cnt[i - 'a']++;

    int mn = 0;
    while (cnt[mn]) mn++;

    ll res = goMatch(mn, "", 0, a, b);

    //cout << a << ' ' << b << ' ' << res << '\n';
    return res;
}

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b) {

    int n = a.size();

    vector<vector<ll>> res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }

    return res;
}

vector<ll> mult(vector<ll>& a, vector<vector<ll>>& b) {

    int n = a.size();

    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i] += a[j] * b[i][j] % mod;
            res[i] %= mod;
        }
    }

    return res;
}

void solve(ll h, ll w) {

    w--;
    int sn = pList[h - 1].size();
    vector<ll> res(sn, 1);

    for (int i = 0; i < sn; i++) {

        int tcnt = 0;
        vector<int> cnt(7);
        for (auto f : pList[h - 1][i]) {
            cnt[f - 'a']++;
        }

        while (cnt[tcnt])tcnt++;

        for (int j = 0; j < tcnt; j++) {
            res[i] *= 16ll- j;
            res[i] %= mod;
        }
    }

    for (int i = 0; i < 63; i++) {

        if (w & (1ll << i)) {
            res = mult(res, dp[h - 1][i]);
        }
    }

    ll rans = 0;
    for (auto f : res) {
        rans += f;
        rans %= mod;
    }

    cout << rans <<  '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    for (int i = 0; i < 66; i++) {
        for (int j = 0; j < 6; j++) {
            int sz = pList[j].size();
            dp[j][i] = vector<vector<ll>>(sz, vector<ll>(sz));
        }
    }

    for (int i = 1; i <= 6; i++) {

        int sz = pList[i - 1].size();
        //cout << "dp: " << i << '\n';

        for (int a = 0; a < sz; a++) {
            for (int b = 0; b < sz; b++) {
                ll res = cntPattern(pList[i - 1][a], pList[i - 1][b]);
                dp[i - 1][0][b][a] = res;
            }
        }

        //for (int a = 0; a < sz; a++) {
        //    for (int b = 0; b < sz; b++) {
        //        cout << dp[i - 1][0][a][b] << ' ';
        //    }
        //    cout << '\n';
        //}

    }

    for (int i = 1; i < 66; i++) {
        for (int j = 0; j < 6; j++) {
            dp[j][i] = mult(dp[j][i - 1], dp[j][i - 1]);
        }
    }

    int q;
    cin >> q;
    while (q--) {

        ll h, w;
        cin >> h >> w;

        solve(h, w);
    }


}