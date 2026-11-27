#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> A(n);
    for (auto& i : A) {
        cin >> i;
        i %= k;
    }

    ll tot = 0;
    for (auto i : A) tot += i;

    if (tot % k != 0) {
        cout << "blobsad";
        return 0;
    }

    int l = 0, r = 0, ix = -1;
    ll val = 0, ans = 0;
    while (r < n) {

        while (val < k && r < n) {
            val += A[r];
            if (val >= (k+1) / 2 && ix == -1) ix = r;
            r++;
        }
        if (ix == -1) break;
        val -= k;

        A[r - 1] -= val;

        for (int i = l; i < r; i++) {
            ans += A[i] * abs(i - ix);
        }

        ix = -1;
        if (val != 0) {
            l = r-1;
            A[l] = val;
            if (val >= (k + 1) / 2) ix = l;
        }
        else l = r;
    }
    cout << ans;

}