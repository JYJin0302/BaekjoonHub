#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct Qur {
    char t;
    int a, b;
};
vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}
int sn;

int seg[404040];
void update(int ix, int val) {
    for (ix += sn; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}

int getMax(int l, int r) {
    int res = 0;
    for (l += sn, r += sn; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

set<pair<int, int>> p[202020];


void solve() {

    int n;
    cin >> n;
    vector<Qur> q;
    for (int i = 0; i < n; i++) {
        char c;
        int a = -1, b = -1;
        cin >> c;
        if (c == 'D') cin >> a >> b;
        else cin >> a;

        q.push_back(Qur(c, a, b));
        num.push_back(b);
    }

    sort(all(num));
    num.erase(unique(all(num)));

    sn = num.size();

    vector<pair<int, int>> A(n + 10);

    int idx = 0;
    for (int i = 0; i < n; i++) {

        Qur cur = q[i];
        if (cur.t == 'D') {
            int a = cur.a;
            int b = getIdx(cur.b);
            A[++idx] = mp(a, b);

            update(b, a);
            p[b].insert(mp(a, idx));
        }
        else {
            auto [a, b] = A[cur.a];
            int l = b + 1, r = sn - 1, res = -1;
            if (!p[b].empty()) {
                auto ix = p[b].lower_bound(mp(a + 1, -1));
                if (ix != p[b].end()) {
                    cout << (*ix).y << '\n';
                    continue;
                }
            }

            while (l <= r) {
                int md = (l + r) >> 1;
                int mx = getMax(b + 1, md + 1);
                if (mx >= a) {
                    res = md;
                    r = md - 1;
                }
                else l = md + 1;
            }

            if (res == -1) cout << "NE\n";
            else {
                auto ix = p[res].lower_bound(mp(a, -1));
                assert(ix != p[res].end());
                cout << (*ix).y << '\n';
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}