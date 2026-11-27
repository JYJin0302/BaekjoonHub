#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    if (abs(a.first) == abs(b.first)) return a.second < b.second;
    return abs(a.first) < abs(b.first);
}

vector<int> seg;
void update(int l, int r, int n, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] += v;
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, n * 2, u, v);
    update(m + 1, r, n * 2 + 1, u, v);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int getSum(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return getSum(l, m, n * 2, sl, sr) + getSum(m + 1, r, n * 2 + 1, sl, sr);
}
int getIdx(int l, int r, int n, int k) {

    if (l == r) {
        if (seg[n] <= k) return l - 1;
        return l;
    }

    int m = (l + r) >> 1;
    if (seg[n * 2 + 1] <= k) return getIdx(l, m, n * 2, k - seg[n * 2 + 1]);
    return getIdx(m + 1, r, n * 2 + 1, k);
}

int n;
int toL[500010], toR[500010];

int getL(int x) {
    if (x < 0) return x;
    if (toL[x] == x) return x;
    return toL[x] = getL(toL[x]);
}
int getR(int x) {
    if (x >= n) return x;
    if (toL[x] == x) return x;
    return toR[x] = getR(toR[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    ll c, r;
    cin >> n >> c >> r;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    int sn = 1;
    while (sn < n) sn *= 2;
    seg = vector<int>(sn * 2);

    ll cnt = 0, pv = 0;
    vector<int> L(n + 5), R(n + 5);


    int ix = 0;
    while (ix < n) {

        if (A[ix] == 0) {
            L[ix] = 0;
            R[ix] = 0;
            ix++;
            cnt++;
            continue;
        }


        int nx = ix;
        while (nx < n && A[nx] * A[ix] >= 0) nx++;

        int nx2 = nx - 1;
        while (A[nx2] == 0) nx2--;


        for (int i = ix; i <= nx2; i++) {
            L[i] = ix;
            R[i] = nx2;
        }
        for (int i = nx2 + 1; i < nx; i++) {
            L[i] = i;
            R[i] = i;
        }
        cnt += nx - ix - 1;
        ix = nx;
    }

    for (int i = 0; i <= n; i++) {
        toL[i] = toR[i] = i;
    }

    vector<pair<ll, ll>> B(n);
    for (int i = 0; i < n; i++) {
        B[i] = { A[i] , i };
        if (A[i] == 0) {
            update(0, sn - 1, 1, i, 1);
            toL[i] = getL(i - 1);
            toR[i] = getR(i + 1);
        }
    }

    sort(B.begin(), B.end(), cmp);

    ll ans = r * cnt;

    cnt = 0;
    for (int i = 1; i < n; i++) {
        if (i > 0 && A[i] * A[i - 1] > 0) cnt++;
    }

    int tix = 0;
    while (tix < n && A[tix] == 0) tix++;


    while (tix < n) {
        while (tix < n && A[tix] != 0) tix++;
        int nx = tix;
        while (nx < n&& A[nx] == 0) nx++;

        if (nx == n) break;

        bool ck = (nx - tix) % 2 == 1;
        ck ^= A[tix - 1] * A[nx] > 0;

        if (ck) cnt++;
        tix = nx;
    }

    ans = min(ans, c + r * cnt);

    for (auto i : B) {

        ll val, ix;
        tie(val, ix) = i;


        if (val == 0) {
            continue;
        }

        ll rsum = getSum(0, sn - 1, 1, ix, sn - 1);
        //int lsum = getSum(0, sn - 1, 1, 0, ix);

        ll rdx = min(R[ix], n - 1);
        if (rsum != 0) rdx = min(R[ix], getIdx(0, sn - 1, 1, rsum - 1) - 1);

        ll ldx = max(L[ix], getIdx(0, sn - 1, 1, rsum) + 1);

        ll ri = getR(ix + 1);
        ll li = getL(ix - 1);


        if (ri < n) {
            bool ck = ((ri - ix - 1) % 2 == 1);
            ck ^= (A[ri] * A[ix] > 0);

            if (ck) {
                //   cout << "dc right\n";
                cnt--;
            }
        }
        if (li >= 0) {
            bool ck = ((ix - li - 1) % 2 == 1);
            ck ^= (A[li] * A[ix] > 0);

            if (ck) {
                //  cout << "dc left\n";
                cnt--;
            }
        }

        if (ri < n && li >= 0) {
            bool ck = ((ri - li - 1) % 2 == 1);
            ck ^= (A[li] * A[ri] > 0);

            if (ck) {
                //  cout << "ADd bth\n";
                cnt++;
            }
        }

        toR[ix] = ri;
        toL[ix] = li;/*
        cout << "cur: " << val << ' ' << ix << ' ' << cnt << ' ' << li << ' ' << ri << '\n';
        cout << ldx << ' ' << rdx << '\n';
        cout << "REs: " << (abs(val) + 1) * c + cnt * r << '\n';*/

        ans = min(ans, (1 + abs(val)) * c + cnt * r);
        update(0, sn - 1, 1, ix, 1);
    }

    cout << ans;
}
