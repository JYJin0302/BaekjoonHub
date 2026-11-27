#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    return get<0>(a) > get<0>(b);
}

vector<int> seg;

void update(int l, int r, int n, int k) {
    if (l > k || r < k) return;

    if (l == k && r == k) {
        seg[n]++;
        return;
    }

    int mid = (l + r) / 2;

    update(l, mid, n * 2, k);
    update(mid + 1, r, n * 2 + 1, k);

    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int subsum(int l,int r, int n, int sl, int sr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int mid = (l + r) / 2;

    return subsum(l, mid, n * 2, sl, sr) + subsum(mid + 1, r, n * 2 + 1, sl, sr);
}

// 왼쪽부터 sweep -> 가능한 개수 저장
// 오른쪽부터 sweep -> 가능한 개수 저장
// 왼쪽 개수 * 오른쪽 개수의 합
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, a, b, c, mod = 1e9 + 7;
    cin >> n;

    int asize = 1;
    while (asize < 400001) asize *= 2;
    // 200000 -> 0

    vector<tuple<int ,int,int>> A;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        A.push_back({ a, b, i });
    }

    // 왼쪽
    sort(A.begin(), A.end());
    vector<int> L(n);
    seg = vector<int>(asize * 2);

    for (auto i : A) {
        tie(a, b, c) = i;

        L[c] = subsum(asize, asize * 2 - 1, 1, asize + 200000 + b + 1, asize * 2 - 1);
        update(asize, asize * 2 - 1, 1, asize + 200000 + b);
    }

    // 오른쪽
    sort(A.begin(), A.end(), comp);
    vector<int> R(n);
    seg = vector<int>(asize * 2);

    for (auto i : A) {
        tie(a, b, c) = i;

        R[c] = subsum(asize, asize * 2 - 1, 1, asize + 200000 + b + 1, asize * 2 - 1);
        update(asize, asize * 2 - 1, 1, asize + 200000 + b);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (ll)L[i] * R[i];
        ans %= mod;
    }

    cout << ans;
}