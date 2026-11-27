#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1000000007;
vector<ll> seg;

ll init(int s, int f, int n) {

    if (s == f) return seg[s];
    int mid = (s + f) / 2;

    ll n1 = init(s, mid, n * 2);
    ll n2 = init(mid + 1, f, n * 2 + 1);

    return seg[n] = (n1 * n2) % mod;

}

ll subsum(int s, int f, int n, int left, int right) {
    if (left > f || right < s) return 1;
    if (s >= left && f <= right) return seg[n];

    int mid = (s + f) / 2;

    ll n1 = subsum(s, mid, n * 2, left, right);
    ll n2 = subsum(mid + 1, f, n * 2 + 1, left, right);
    return  (n1 * n2) % mod;
}

void update(int s, int f, int n, int t, ll den, ll num) {
    if (t < s || t > f) return;
    if (den != 0) seg[n] /= den;
    else seg[n] = 1;
    seg[n] *= num;
    if (s == f) return;
    int mid = (s + f) / 2;
    update(s, mid, n * 2, t, den, num);
    update(mid + 1, f, n * 2 + 1, t, den, num);
    seg[n] = (seg[n * 2] * seg[n * 2 + 1]) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, a, b, c;
    cin >> n >> m >> k;
    ll arrsize = 1;
    while (arrsize < n) arrsize *= 2;

    seg = vector<ll>(2 * arrsize, 1);

    for (int i = 0; i <= n - 1; i++) {
        cin >> seg[i + arrsize];
    }

    init(arrsize, arrsize * 2 - 1, 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            ll den = seg[arrsize - 1 + b];
            ll num = c;
            update(arrsize, arrsize * 2 - 1, 1, arrsize - 1 + b, den, num);

        }
        else if (a == 2) {
            cout << subsum(arrsize, arrsize * 2 - 1, 1, arrsize - 1 + b, arrsize - 1 + c) << '\n';

        }
    }

}