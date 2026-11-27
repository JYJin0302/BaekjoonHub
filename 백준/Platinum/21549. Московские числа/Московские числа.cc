#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll val[26];
ll dp[26][303030];
int from[26][303030];

const ll INF = 1e18;
void solve() {

    string s;
    cin >> s;

    int n = s.size();
    
    ll delta = 0;
    vector<bool> chk(n);
    char tc = 'A';
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '?' || s[i] >= tc) chk[i] = 1;
        else {
            chk[i] = 0;
            delta -= val[s[i] - 'A'];
        }
        if (s[i] != '?') tc = max(tc, s[i]);
    }


    string ts = s;
    for (int i = 1; i < n + 10; i++) {
        for (int j = 0; j < 26; j++) {
            from[j][i] = -1;
        }
    }

    vector<int> iLst;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') iLst.push_back(i);
    }
    if (s[n - 1] != '?') iLst.push_back(n - 1);

    int tn = iLst.size();

    int pv = -1;
    for (int i = 0; i < tn; i++) {

        int mi = -1;
        vector<ll> tdp(26);
        ll del = 0;
        int pos = iLst[i];
        stack<ll> st;
        for (int j = pv + 1; j < pos; j++) {
            if (!chk[j]) continue;
            ll v = val[s[j] - 'A'];
            mi = max(mi, s[j] - 'A');
            while (!st.empty() && st.top() < v) {
                del -= 2 * st.top();
                st.pop();
            }
            st.push(v);
            del += v;
        }

        for (int j = 0; j < 26; j++) {
            while (!st.empty() && st.top() < val[j]) {
                del -= 2 * st.top(); st.pop();
            }
            dp[j][i + 1] = del;
        }

        pair<ll, ll> mx = mp(dp[25][i], 25);
        from[25][i + 1] = 25;

        for (int j = 24; j >= 0; j--) {
            mx = max(mx, mp(dp[j][i] + (j < mi ? -2*val[j] : 0), (ll)j));
            from[j][i + 1] = mx.y;
        }
        for (int j = 0; j < 26; j++) {
            int ix = from[j][i + 1];
            dp[j][i + 1] += dp[ix][i] + val[j];
        }

        pv = iLst[i];
    }

    int ansi = 0;
    if (s[n - 1] != '?') {
        ansi = s[n - 1] - 'A';
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (dp[i][tn] > dp[ansi][tn]) {
                ansi = i;
            }
        }
    }

    cout << dp[ansi][tn] + delta << '\n';

    int ix = tn, ix2 = ansi;
    while (!iLst.empty()) {
        int i1 = iLst.back();
        iLst.pop_back();

        s[i1] = char('A' + ix2);
        ix2 = from[ix2][ix];
        ix--;
    }
    cout << s << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    val[0] = 1;
    for (int i = 1; i < 26; i++) {
        if (i & 1) val[i] = val[i - 1] * 5;
        else val[i] = val[i - 1] << 1;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}