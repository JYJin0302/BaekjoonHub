#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

int root[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void solve() {

    int n, r, d;
    cin >> n >> r;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;
    cin >> d;
    sort(all(A));

    if (A[0].x + A[0].y != 0) {
        cout << 0;
        return;
    }
    for (int i = 0; i < n; i++) root[i] = i;

    // x direction
    vector<pair<int, int>> edg;
    for (int i = 0; i < n; i++) {
        edg.push_back(mp(A[i].x, i));
    }
    sort(all(edg));

    set<pair<int, int>> st;
    for (auto& [v, i] : edg) {
        int l = A[i].y;
        auto iter = st.lower_bound(mp(l, -1));
        while (iter != st.end() && (*iter).x <= l + r) {
            int ix = (*iter).y;

            if (A[ix].x + r + d >= A[i].x && find(ix) != find(i)) {
                root[root[ix]] = root[i];
                //cout << "union: " << ix << ' ' << i << '\n';
            }
            st.erase(iter++);
        }
        st.insert(mp(l, i));
        st.insert(mp(l + r, i));

        /*for (auto f : st) cout << f.first << ' ' << f.second << " | ";
        cout << '\n';*/
    }
    st.clear();

    // y direction
    edg.clear();
    for (int i = 0; i < n; i++) {
        edg.push_back(mp(A[i].y, i));
    }
    sort(all(edg));

    for (auto& [v, i] : edg) {
        int l = A[i].x;
        auto iter = st.lower_bound(mp(l, -1));
        while (iter != st.end() && (*iter).x <= l + r) {
            int ix = (*iter).y;

            if (A[ix].y + r + d >= A[i].y && find(ix) != find(i)) {
                root[root[ix]] = root[i];
                //cout << "union: " << ix << ' ' << i << '\n';
            }
            st.erase(iter++);
        }
        st.insert(mp(l, i));
        st.insert(mp(l + r, i));

       /* for (auto f : st) cout << f.first << ' ' << f.second << " | ";
        cout << '\n';*/
    }
    st.clear();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == find(0)) {
            ans = max(ans, A[i].x + A[i].y + 2 * r);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}