#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


ll n;

int seg[404040];

void update(int ix) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix]++;
    }
}

ll getSum(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

ll getVal(vector<int> v1, vector<int> v2) {

    for (int i = 0; i <= n * 2 + 10; i++) seg[i] = 0;

    vector<int> conv(n + 1);
    for (int i = 0; i < n; i++) {
        conv[v1[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) v2[i] = conv[v2[i]];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += getSum(v2[i], n + 1);
        update(v2[i]);
    }
    return res;
}

void solve() {

    cin >> n;

    vector<int> A(n), B(n), C(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;
    for (auto& i : C) cin >> i;

    ll ans = 0;

    ans += getVal(A, B);
    ans += getVal(B, C);
    ans += getVal(C, A);

    ans /= 2;

    ans = n * (n - 1) / 2 - ans;
    cout << ans;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}