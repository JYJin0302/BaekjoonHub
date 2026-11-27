#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000000

int arrsize;
vector<ll> A;
vector<ll> subsum;

vector<pair<int ,int>> seg;  // 구간 최솟값, idx
pair<int, int> init(int l, int r, int n) {
    if (l == r) return seg[n];

    int mid = (l + r) / 2;
    return seg[n] = min(init(l, mid, n * 2), init(mid + 1, r, n * 2 + 1));
}

pair<int, int> submin(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return { INF, -1 };
    if (l >= sl && r <= sr) return seg[n];

    int mid = (l + r) / 2;
    return min(submin(l, mid, n * 2, sl, sr), submin(mid + 1, r, n * 2 + 1, sl, sr));
}

ll solve(int l, int r) {

    if (l > r) return 0;

    pair<int, int> p = submin(arrsize, arrsize * 2 - 1, 1, arrsize + l, arrsize + r);

    return max({ p.first * (subsum[r] - subsum[l] + A[l]), solve(l, p.second - 1), solve(p.second + 1, r) });
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n;
    cin >> n;
    
    arrsize = 1;
    while (arrsize < n) arrsize *= 2;
    seg = vector<pair<int, int>>(arrsize * 2, { INF, -1 });

    A = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[i] = x;
        seg[arrsize + i] = { x, i };
    }

    init(arrsize, arrsize * 2 - 1, 1);
    subsum = vector<ll>(n);
    subsum[0] = A[0];
    for (int i = 1; i < n; i++) subsum[i] = subsum[i - 1] + A[i];

    cout << solve(0, n - 1);
}