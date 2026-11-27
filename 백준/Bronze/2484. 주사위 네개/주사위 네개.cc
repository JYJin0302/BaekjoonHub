#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct D {
    int v[4];
    int vv = -1;

    int val() {
        if (vv != -1) return vv;
        sort(v, v + 4);

        int res = 0;
        if (v[0] == v[3]) res = 50000 + 5000 * v[0];
        else if (v[0] == v[2] || v[1] == v[3]) res = 10000 + 1000 * v[1];
        else if (v[0] == v[1] && v[2] == v[3]) res = 2000 + 500 * v[0] + 500 * v[2];
        else if (v[0] == v[1] || v[1] == v[2]) res = 1000 + 100 * v[1];
        else if (v[2] == v[3]) res = 1000 + 100 * v[2];
        else res = 100 * v[3];
        return vv = res;
    }
    bool operator<(D& o) {
        return (*this).val() > o.val();
    }
};
void solve() {
    int n;
    cin >> n;
    vector<D> A(n);
    for (auto& i : A) {
        for (int j = 0; j < 4; j++) cin >> i.v[j];
    }
    sort(all(A));
    cout << A[0].val();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}