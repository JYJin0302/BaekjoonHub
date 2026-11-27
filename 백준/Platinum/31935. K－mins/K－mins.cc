#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        B.push_back(mp(A[i], i));
    }
    sort(all(B));

    set<int> st;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ix = B[i].y;

        vector<int> L, R;

        if (!st.empty()) {
            auto iter = st.lower_bound(ix);
            while (iter != st.begin() && L.size() <= k) {
                --iter;
                L.push_back(*iter);
            }
            iter = st.lower_bound(ix);
            while (iter != st.end() && R.size() <= k) {
                R.push_back(*iter);
                iter++;
            }
        }
        vector<int> tL(k+1), tR(k+1);
        for (int i = 0; i < L.size(); i++) {
            if (i) tL[i] = L[i - 1] - L[i];
            else tL[i] = ix - L[i];
        }
        if (L.size() != k + 1) {
            tL[L.size()] = (L.empty() ? ix : L.back()) + 1;
        }
        for (int i = 0; i < R.size(); i++) {
            if (i) tR[i] = R[i] - R[i-1];
            else tR[i] = R[i] - ix;
        }
        if (R.size() != k + 1) {
            tR[R.size()] = n - (R.empty() ? ix : R.back());
        }

        for (int f = 0; f < k; f++) {
            ans += 1ll * B[i].x * tL[f] * tR[k-1 - f];
        }


        st.insert(ix);
    }
    cout << ans;

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