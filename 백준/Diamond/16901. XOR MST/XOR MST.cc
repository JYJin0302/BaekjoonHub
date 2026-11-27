#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct Node {
    Node* ch[2];
    int idx;
    Node() {
        ch[0] = ch[1] = NULL;
        idx = -1;
    }
};

void insert(Node* cur, int pos, int val, int idx) {
    if (pos == -1) {
        cur->idx = idx;
        return;
    }

    int v = 0;
    if (val & (1 << pos)) v = 1;

    if (!cur->ch[v]) {
        cur->ch[v] = new Node();
    }
    insert(cur->ch[v], pos - 1, val, idx);
}

int getVal(Node* cur, int pos, int val, int tar) {
    if (!cur) return -1;
    if (pos == -1) {
        return cur->idx;
    }

    int v = 0;
    if (val & (1 << pos)) v = 1;

    if (pos > tar) {
        return getVal(cur->ch[v], pos - 1, val, tar);
    }

    if (pos == tar) {
        return getVal(cur->ch[1-v], pos - 1, val, tar);
    }

    if (cur->ch[v]) return getVal(cur->ch[v], pos - 1, val, tar);
    else return getVal(cur->ch[1-v], pos - 1, val, tar);

}

int R[202020];
int find(int n) {
    if (R[n] == n) return n;
    return R[n] = find(R[n]);
}

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    sort(all(A));

    vector<pair<int, pair<int, int>>> edg;

    Node* root = new Node();
    for (int i = 0; i < n; i++) {


        for (int f = 30; f >= 0; f--) {
            int ix = getVal(root, 29, A[i], f);
            if (ix != -1) {
                edg.push_back(mp(A[i] ^ A[ix], mp(ix, i)));
            }
        }

        insert(root, 29, A[i], i);
    }

    sort(all(edg));
    edg.erase(unique(all(edg)), edg.end());

    for (int i = 0; i < n; i++) R[i] = i;

    ll ans = 0;
    for (auto f : edg) {
        auto [a, b] = f.y;

        //cout << f.x << " | " << a << ' ' << b << '\n';
        a = find(a), b = find(b);
        if (a != b) {
            ans += f.x;
            R[a] = b;
        }
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