#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll L[500001], R[500001], dpL[500001], dpR[500001];


ll getVal(int l, int r) {

    // l과 r 이 같은 구간
    if (l + R[l] == r + R[r]) {
        ll len = r - l + 1;
        return len * (len + 1) / 2;
    }

    ll res = 0;
    res += R[l] * (R[l] + 1) / 2;
    res += L[r] * (L[r] + 1) / 2;
    
    int tr = r - L[r];
    int tl = l + R[l];
    res += dpL[tr] - dpL[tl - 1];
    return res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    L[0] = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] >= A[i - 1]) L[i] = L[i - 1] + 1;
        else L[i] = 1;
    }

    R[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] <= A[i + 1]) R[i] = R[i + 1] + 1;
        else R[i] = 1;
    }

    dpL[0] = 1;
    for (int i = 1; i < n; i++) {
        dpL[i] = dpL[i - 1] + L[i];
    }
    dpR[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dpR[i] = dpR[i + 1] + R[i];
    }

    while (t--) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        ll ans = 1e15;
        int tl = 0, tr = n - 1;
        while (tl <= tr) {
            int md = (tl + tr) >> 1;

            ll ans1 = getVal(a, md);
            ll ans2 = getVal(md, b);

            ans = min(ans, max(ans1, ans2));

            if (ans2 > ans1) tl = md + 1;
            else tr = md - 1;
        }
        cout << ans << '\n';
    }

}
