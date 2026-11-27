#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

ll init(int s, int f, int n) {

    if (s == f) return seg[s];
    int mid = (s + f) / 2;

    return seg[n] = init(s, mid, n * 2) + init(mid + 1, f, n * 2 + 1);

}

ll subsum(int s, int f, int n, int left, int right) {
    if (left > f || right < s) return 0;
    if (s >= left && f <= right) return seg[n];

    int mid = (s + f) / 2;

    return subsum(s, mid, n * 2, left, right) + subsum(mid + 1, f, n * 2 + 1, left, right);

}

void update(int s, int f, int n, int t, ll diff) {
    if (t < s || t > f) return;
    seg[n] += diff;
    if (s == f) return;
    int mid = (s + f) / 2;
    update(s, mid, n * 2, t, diff);
    update(mid + 1, f, n * 2 + 1, t, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, a, b, c;
    cin >> n >> m >> k;
    ll arrsize = 1;
    while (arrsize < n) arrsize *= 2;

    seg = vector<ll>(2 * arrsize);

    for (int i = 0; i <= n-1; i++) {
        cin >> seg[i + arrsize];
    }

    init(arrsize, arrsize*2 - 1, 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            ll dif = c - seg[arrsize - 1 + b];
            update(arrsize, arrsize * 2 - 1, 1, arrsize - 1 + b, dif);
        }
        else if (a == 2) {
            cout << subsum(arrsize, arrsize * 2 - 1, 1, arrsize - 1 + b, arrsize - 1 + c) << '\n';

        }
    }
    
}