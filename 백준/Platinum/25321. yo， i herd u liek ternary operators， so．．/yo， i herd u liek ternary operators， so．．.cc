#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

ll f[600030], C[300030];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    f[0] = 1;
    for (int i = 1; i <= 600000; i++) {
        f[i] = f[i - 1] * i % mod;
    }

    for (int i = 0; i <= 300000; i++) {
        C[i] = f[i * 2] * fastPow(f[i], mod - 2, mod) % mod;
        C[i] = C[i] * fastPow(f[i + 1], mod - 2, mod) % mod;

    }

    //for (int i = 0; i <= 10; i++) cout << C[i] << ' ';

    string s;
    cin >> s;

    stack<int> st;
    st.push(0);
    ll ans = 1;
    for (auto i : s) {
        if (isalpha(i)) continue;

        /*stack<int> tmp = st;
        vector<int> res;
        while (!tmp.empty()) {
            res.push_back(tmp.top());
            tmp.pop();
        }
        reverse(res.begin(), res.end());

        for (auto k : res) cout << k << ' ';
        cout << '\n';*/

        if (i == '?') {
            st.push(0);
        }
        else {
            // i == ':'
            int x = st.top();
            st.pop();

            ans = ans * C[x] % mod;
            st.top()++;
        }
    }
    ans = ans * C[st.top()] % mod;
    cout << ans;
}