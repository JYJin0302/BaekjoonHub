#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    vector<int> pos(n);
    for (auto& i : pos) cin >> i;

    int mx = pos.back() + 200010;
    vector<bool> vis(mx);
    for (auto f : pos) vis[f] = 1;


    set<int> st;
    for (int i = 1; i < mx; i++) if (!vis[i]) st.insert(i);


    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;

        auto iter = st.lower_bound(pos[x]);
        cout << *iter << '\n';

        st.insert(pos[x]);
        pos[x] = *iter;
        st.erase(iter);
    }


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}