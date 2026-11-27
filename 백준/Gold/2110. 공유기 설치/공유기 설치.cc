#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int n, c;
    cin >> n >> c;

    vector<int>A(n);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());

    int maxn = A.back() - A[0];

    ll ans = 0;

    int l = 0, r = maxn * 2;
    while (l <= r && l < maxn) {

        ll mid = (l + r) / 2;

        int ind = 1, cnt = 1;
        int pre = A[0];
        while (ind < n && cnt < c) {

            if (A[ind] - pre >= mid) {
                pre = A[ind];
                cnt++;
            }
            ind++;
        }

        if (cnt == c) {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;
}