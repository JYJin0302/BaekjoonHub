#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n, q;
int segMax[303030];
void update(int ix, int val) {
    for (ix += n; ix; ix >>= 1) {
        segMax[ix] = max(segMax[ix], val);
    }
}

int getMax(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, segMax[l++]);
        if (r & 1) res = max(res, segMax[--r]);
    }
    return res;
}

ll seg[303030];
ll lazy[303030];

void goLazy(int l, int r, int n) {
    if (lazy[n]) {
        seg[n] = lazy[n] * (r - l + 1);
        if (l != r) {
            lazy[n * 2] = max(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = max(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = 0;
    }
}
void update(int l, int r, int n, int ul, int ur, ll v) {
    goLazy(l, r, n);
    if (l > ur || r < ul)return;
    if (l >= ul && r <= ur) {
        lazy[n] = v;
        goLazy(l, r, n);
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, ul, ur, v);
    update(md + 1, r, n * 2 + 1, ul, ur, v);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}



void solve() {

    cin >> n >> q;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    int sn = 1;
    while (sn < n) sn *= 2;

    ll totB = 0;
    for (int i = 0; i < n; i++) {
        update(i, A[i]);
    }
    for (int i = 0; i < n; i++) {
        ll lMax = getMax(0, i + 1);
        ll rMax = getMax(i, n);

        update(0, sn - 1, 1, i, i, min(lMax, rMax));
        totB += A[i];
    }

    //  cout << totW << ' ' << totB << '\n';

    while (q--) {

        int idx, x;
        cin >> idx >> x;
        idx--;

        int ldx = idx, rdx = idx;
        ll lval = -1, rval = -1;
        {
            int l = 0, r = idx - 1;
            while (l <= r) {
                int md = (l + r) >> 1;
                ll tmp = getMax(md, idx + 1);
                if (tmp > x) {
                    ldx = md;
                    lval = tmp;
                    l = md + 1;
                }
                else r = md - 1;
            }
        }
        {
            int l = idx + 1, r = n - 1;
            while (l <= r) {
                int md = (l + r) >> 1;
                ll tmp = getMax(idx + 1, md + 1);
                if (tmp > x) {
                    rdx = md;
                    rval = tmp;
                    r = md - 1;
                }
                else l = md + 1;
            }
        }

       // cout << lval << ' ' << ldx << " + " << rval << ' ' << rdx << '\n';
        if (lval != -1 && rval != -1) {
            // ok
        }
        else if (lval != -1) {
            update(0, sn - 1, 1, ldx + 1, idx, x);
        }
        else if (rval != -1) {
            update(0, sn - 1, 1, idx, rdx - 1, x);
        }
        else {
            lval = getMax(0, idx);
            {
                int l = 0, r = idx - 1;
                while (l <= r) {
                    int md = (l + r) >> 1;
                    ll tmp = getMax(md, idx + 1);
                    if (tmp == lval) {
                        ldx = md;
                        l = md + 1;
                    }
                    else r = md - 1;
                }
            }
            update(0, sn - 1, 1, ldx + 1, idx - 1, lval);

            rval = getMax(idx + 1, n);
            {
                int l = idx + 1, r = n - 1;
                while (l <= r) {
                    int md = (l + r) >> 1;
                    ll tmp = getMax(idx + 1, md + 1);
                    if (tmp == rval) {
                        rdx = md;
                        r = md - 1;
                    }
                    else l = md + 1;
                }
            }
            update(0, sn - 1, 1, idx + 1, rdx - 1, rval);

            update(0, sn - 1, 1, idx, idx, x);
           // cout << "UPd : " << lval << ' ' << ldx << " + " << rval << ' ' << rdx << '\n';
        }

        goLazy(0, sn - 1, 1);
        ll s = seg[1];

        update(idx, x);

        totB += x - A[idx];
        A[idx] = x;
        //cout << s << " | " << totB << ' ' << s - totB << '\n';
        cout << s - totB << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}