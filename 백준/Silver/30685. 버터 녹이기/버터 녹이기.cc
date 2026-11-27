#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;
    sort(A.begin(), A.end());

    // binary search

    int l = 0, r = 1e9 + 10, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;

        bool ok = 1;
        int pv = -2e9 - 10;
        for (int i = 0; i < n; i++) {
            if (A[i].first - min(A[i].second / 2, mid) <= pv) ok = 0;
            pv = A[i].first + min(A[i].second / 2, mid);
        }

        if (ok) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    if (r == 1e9 + 10) cout << "forever";
    else cout << ans;

}
