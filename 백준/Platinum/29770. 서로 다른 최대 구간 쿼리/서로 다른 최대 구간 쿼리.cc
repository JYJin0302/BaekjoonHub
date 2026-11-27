#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int R[505050];

int n;
int seg[1111111];

void update(int ix, int val) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}

int getMax(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> cnt(n + 1);

    int r = 0;
    for (int i = 0; i < n; i++){
        while (r < n && cnt[A[r]] == 0) {
            cnt[A[r]]++;
            r++;
        }
        R[i] = r - i;
        cnt[A[i]]--;
    }

    /*for (int i = 0; i < n; i++) cout << R[i] << ' ';
    cout << '\n';*/

    for (int i = 0; i < n; i++) {
        update(i, R[i]);
    }


    int q;
    cin >> q;
    while (q--) {
        
        int l, r;
        cin >> l >> r;
        l--, r--;

        int tl = l, tr = r, ix = -1;
        while (tl <= tr) {

            int md = (tl + tr) >> 1;

            if (R[md] + md > r) {
                ix = md;
                tr = md - 1;
            }
            else tl = md + 1;

        }

        assert(ix != -1);
        int res = r - ix + 1;
       // cout << "TMP: " << ix << ' ' << getMax(l, ix) << ' ';
        res = max(res, getMax(l, ix));
        cout << res << '\n';
    }


}