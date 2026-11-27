#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

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
    int n, a;
    cin >> n;
    ll arrsize = 1;
    while (arrsize < n) arrsize *= 2;

    map<int, int> ind;
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        ind[a] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        B[ind[a]] = i;
    }

    seg = vector<ll>(2 * arrsize);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll temp = subsum(arrsize, arrsize * 2 - 1, 1, arrsize + B[i], arrsize * 2 - 1);
        cnt += temp;
        update(arrsize, arrsize * 2 - 1, 1, arrsize + B[i], 1);
    }

    cout << cnt;
}