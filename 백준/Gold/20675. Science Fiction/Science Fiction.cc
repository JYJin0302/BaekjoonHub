#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool bChk(int v, int pos) {
    return v & (1 << pos);
}

int A[1 << 10];
set<pair<int, int>> st;
vector<pair<int, int>> ans;
void goSwap(int u, int v) {
    st.erase(st.find(mp(A[u], u)));
    st.erase(st.find(mp(A[v], v)));
    swap(A[u], A[v]);
    st.insert(mp(A[u], u));
    st.insert(mp(A[v], v));
    ans.push_back(mp(u, v));
}


void solve() {

    int n;
    cin >> n;

    int sn = 1 << n;
    for (int i = 0; i < sn; i++) cin >> A[i];

    for (int i = 0; i < sn; i++) {
        st.insert(mp(A[i], i));
    }

    for (int i = 0; i < sn; i++) {
        auto f = *st.begin();

        int cur = f.y;
        int tar = i;

        for (int j = 0; j < n; j++) {
            if (bChk(tar, j) && !bChk(cur, j)) {
                goSwap(cur, cur ^ (1 << j));
                cur ^= 1 << j;
            }
        }

        for (int j = 0; j < n; j++) {
            if (!bChk(tar, j) && bChk(cur, j)) {
                goSwap(cur, cur ^ (1 << j));
                cur ^= 1 << j;
            }
        }

        st.erase(st.begin());
    }


    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}