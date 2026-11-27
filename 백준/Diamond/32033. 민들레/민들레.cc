#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int L[202020], R[202020];
int root[202020];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return 0;
    root[u] = v;
    return 1;
}

vector<pair<int, int>> ndM[202020];

void solve() {

    int q;
    cin >> q;

    for (int i = 0; i <= q + 10; i++) root[i] = i;

    set<pair<int, int>> st;
    st.insert(mp(0, 0));
    int l = 0, r = 0;

    map<int, int> mdx;
    mdx[0] = 0;
    vector<int> sd = { 0 };
    int ix = 0;

    ll ans = 1;
    int cnt = 1;
    int oper = 0;
    for (int i = 1; i <= q; i++) {
        for (auto [a, b] : ndM[oper]) {
            if (merge(a, b)) {
                cnt--;
                //cout << "Merged: " << sd[a] << ' ' << sd[b] << '\n';
            }
        }

        //cout << "State : " << l << ' ' << r << " | " << cnt << ' ' << oper << '\n';

        char c;
        cin >> c;
        if (c == 'L') {
            l++;
            ans += cnt;
            oper++;

        }
        else if (c == 'R') {
            r++;
            ans += cnt;
            oper++;
        }
        else if (c == 'C') {
            int x;
            cin >> x;

            int curIx = ++ix;
            sd.push_back(x);

            bool ok = 1;
            auto iter = st.lower_bound(mp(x, -1));
            if (iter != st.end()) {
                auto [a, b] = *iter;

                int tl, tr;
                tl = l - L[b];
                tr = r - R[b];
                if (a - tl <= x) ok = 0;
            }

            if (ok && iter != st.begin()) {
                iter--;
                auto [a, b] = *iter;

                int tl, tr;
                tl = l - L[b];
                tr = r - R[b];
                if (a + tr >= x) ok = 0;
            }

            if (ok) {
                iter = st.lower_bound(mp(x, -1));
                if (iter != st.end()) {
                    auto [a, b] = *iter;
                    int tl, tr;
                    tl = l - L[b];
                    tr = r - R[b];
                    int bx = mdx[a];
                    if (oper + a - tl - x - 1 <= 201020) ndM[oper + a - tl - x - 1].push_back(mp(bx, curIx));
                    //cout << "oper add R: " << a - tl - x - 1 << " | " << bx << ' ' << curIx << '\n';
                }
                if (iter != st.begin()) {
                    iter--;
                    auto [a, b] = *iter;
                    int tl = l - L[b];
                    int tr = r - R[b];
                    int bx = mdx[a];
                    if (oper + x - (a + tr) - 1 <= 201020) ndM[oper + x - (a + tr) - 1].push_back(mp(bx, curIx));
                    //cout << "oper add L: " << x - (a + tr) - 1 << " | " << bx << ' ' << curIx << '\n';
                }

                cnt++;
                ans++;
                st.insert(mp(x, i));
                mdx[x] = curIx;
            }


        }
        else {
            cout << ans << '\n';
        }

        L[i] = l, R[i] = r;
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}