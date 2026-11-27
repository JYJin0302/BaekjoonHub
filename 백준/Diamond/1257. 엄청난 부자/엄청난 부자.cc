#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using ll = long long;

ll dp[15101010];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, 0x3f3f3f3f, sizeof(dp));

    ll target;
    cin >> target;

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());

    dp[0] = 0;
    int sz = A[n-1], pv = 1;

    while (1) {
        int cnt = 0;
       // cout << pv << '\n';
        for (int i = pv; i < pv + sz; i++) {
            for (auto f : A) {
                if (i >= f) {
                    dp[i] = min(dp[i], dp[i - f] + 1);
                }
            }
            if (i >= sz && dp[i] == dp[i - sz] + 1) cnt++;
        }

        pv += sz;
        if (cnt == sz)break;
    }

    pv--;/*
    cout << pv << '\n';
    for (int i = 0; i <= pv; i++) cout << dp[i] << ' ';*/


    if (target <= pv) cout << dp[target];
    else {

        ll nt = target % sz;
        ll tv = (ll)pv - sz + nt;

        ll ans = dp[tv] + (target - tv) / sz;
        cout << ans;
    }
}
