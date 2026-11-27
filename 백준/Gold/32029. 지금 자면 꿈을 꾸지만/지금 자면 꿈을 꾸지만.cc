#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a; j++) {

            int curT = 0, cnt = 0;
            for (int f = 0; f < i; f++) {
                if (A[f] >= curT + a) {
                    curT += a;
                    cnt++;
                }
            }
            curT += j * b;
            for (int f = i; f < n; f++) {
                if (A[f] >= curT + a - j) {
                    curT += a - j;
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}