#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;

ll A[505050];
ll cnt[505050];
ll val[505050];

ll ans = 0;
void merge(int u, int v) {
   // cout << "Merge: " << u << " => " << v << '\n';
    ll d = (A[v] - A[u]) * (A[v] - A[u]) % mod;
    ll nval = (val[u] + cnt[u] * d) % mod;

    (ans += nval * cnt[v] % mod + val[v] * cnt[u] % mod) %= mod; 
    cnt[v] += cnt[u];
    (val[v] += nval) %= mod;
}
void solve() {

    int n;
    cin >> n;

    for(int i =0 ; i < n; i++){
        cin >> A[i];
        cnt[i] = 1;
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] <= A[i]) {
            int i1 = st.top(); st.pop();

            if (!st.empty() && A[st.top()] <= A[i]) {
                // connect left
                int tar = st.top();
                merge(i1, tar);
            }
            else {
                // connect right
                merge(i1, i);
            }
        }
        st.push(i);
    }
    while (st.size() >= 2) {
        int v = st.top(); st.pop();
        int u = st.top();
        merge(v, u);
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}