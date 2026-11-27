#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int root[303030];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void solve() {

    int n, k;
    cin >> n >> k;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    
    set<pair<ll, ll>> st;
    for (int i = 0; i < k; i++) {
        st.insert(mp(A[i], i));
    }

    vector<vector<ll>> mLst;

    int ix = k;
    ll ansT = 0;
    ll ansPos = 0;
    while (ix <= n) {
        auto [a, b] = *st.begin();
        st.erase(st.begin());

        vector<ll> iLst = { b };
        while (!st.empty() && (*st.begin()).x == a) {
            iLst.push_back((*st.begin()).y);
            st.erase(st.begin());
        }

        mLst.push_back(iLst);

        while (ix <= n && !iLst.empty()) {
            ll pos = iLst.back(); iLst.pop_back();

            if (ix == n) {
                ansT = a;
                ansPos = pos;
            }
            else {
                st.insert(mp(a + A[ix], pos));
            }
            ix++;
        }
    }
    
    for (int i = 0; i <= n + 10; i++) root[i] = i;

    reverse(all(mLst));
    for (auto v : mLst) {
        bool ok = 0;
        for (auto f : v) {
            int f1 = find(ansPos);
            int f2 = find(f);
            if (f1 == f2) ok = 1;
        }

        if (ok) {
            for (auto f : v) {
                int f1 = find(ansPos);
                int f2 = find(f);
                root[f2] = f1;
            }
        }
    }

    cout << ansT << '\n';
    for (int i = 0; i < k; i++) {
        if (find(ansPos) == find(i)) cout << 1;
        else cout << 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while(t--) solve();
}