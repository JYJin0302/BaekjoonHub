#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

using P = pair<ll, ll>;

vector<pair<P, P>> A;

ll cx = -1;
ld getPos(int ix, ll val) {
    if (val < A[ix].x.x || val > A[ix].y.x) return -1e10;
    ld v1 = 1.0 * (A[ix].y.x - val) / (A[ix].y.x - A[ix].x.x);
    return v1 * (A[ix].x.y - A[ix].y.y) + A[ix].y.y;
}

struct cmp {
    bool operator() (int a, int b) const {
        return getPos(a, cx) < getPos(b, cx);
    }
};


void solve() {

    int n;
    cin >> n;

    A = vector<pair<P, P>>(n);
    for (auto& [a, b] : A) {
        cin >> a.x >> a.y >> b.x >> b.y;
        if (b < a) swap(a, b);
    }

    ll ansx;
    cin >> ansx;

    vector<pair<P, int>> B;
    for (int i = 0; i < n; i++) {
        B.push_back(mp(A[i].x, i));
        B.push_back(mp(A[i].y, i));
    }
    sort(all(B));

    set<int, cmp> st;

    vector<int> nxt(n, -1);
    vector<int> cnt(n);

    vector<int> rmvLst;

    for (auto& [a, b] : B) {
        if (cx != a.x) {
            for (auto f : rmvLst) {
                st.erase(st.find(f));
            }
            rmvLst.clear();
        }
        cx = a.x;
        if (cnt[b]) {
            auto iter = st.find(b);
            if (a.y < A[b].x.y) {
                // get ans
                if (iter != st.begin()) {
                    iter--;
                    int nx = *iter;
                    nxt[b] = nx;
                    iter++;
                }
            }
            // erase
            rmvLst.push_back(b);
        }
        else {
            st.insert(b);
            if (a.y < A[b].y.y) {
                // get ans
                auto iter = st.find(b);
                if (iter != st.begin()) {
                    iter--;
                    int nx = *iter;
                    nxt[b] = nx;
                }
            }
        }
        cnt[b]++;
    }

    pair<ld, int> ans = mp(-1e8, -1);
    for (int i = 0; i < n; i++) {
        ld res = getPos(i, ansx);
        ans = max(ans, mp(res, i));
    }

    if (ans.y == -1) cout << ansx;
    else {
        int ix = ans.y;
        while (nxt[ix] != -1) ix = nxt[ix];

        if (A[ix].x.y < A[ix].y.y) cout << A[ix].x.x;
        else cout << A[ix].y.x;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}