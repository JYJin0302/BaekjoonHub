#include <bits/stdc++.h>
using namespace std;

struct D {
    int l, r, d;
};

int n;
map<pair<int, int>, int> dp;
vector<D> A;

int solve(int l, int r) {

    if (dp[{l, r}] != 0) {
        int val = dp[{l, r}];
        if (val == -1) val = 0;
        return val;
    }

    int md = -1, mi = -1;
    for (int i = 0; i < n; i++) {
        if (A[i].l > l && A[i].r < r) {
            md = max(md, A[i].d);
            if (md == A[i].d) mi = i;
        }
    }
    if (mi == -1) {
        dp[{l, r}] = -1;
        return 0;
    }

    int res = 1e9;

    for (int i = 0; i < n; i++) {
        if (A[i].l >= A[mi].l && A[i].l <= A[mi].r) {
            res = min(res, solve(l, A[i].l) + A[mi].d + solve(A[i].l, r));
        }
    }
    return dp[{l, r}] = res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {

        cin >> n;
        dp.clear();

        A = vector<D> (n);
        for (auto& i : A) cin >> i.l >> i.r >> i.d;

        int ml = A[0].l, mr = A[0].r;

        for (int i = 1; i < n; i++) {

            ml = min(ml, A[i].l);
            mr = max(mr, A[i].r);
        }

        cout << solve(ml - 1, mr + 1) << '\n';
    }

}