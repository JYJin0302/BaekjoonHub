#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());

    int tot = 0;
    for (auto i : A) tot += i;
    int ans = 0;

    if (A[n - 1] >= tot / 2) {
        ans = tot / 2 + A[n - 1] - tot / 2;
    }
    else ans = (tot + 1) / 2;

    if (ans > 1440) ans = -1;
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }
}