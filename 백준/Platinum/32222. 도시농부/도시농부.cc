#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == m) cnt++;
        else A.push_back(x);
    }

    sort(all(A));
    n = A.size();
    int ans = n;

    if (cnt == 0) {
        // try oper3 at A[0];

        int tans = 1;
        int ix = n - 1;
        while (ix >= 3) {
            if (A[ix - 2] * 2 >= m) {
                tans++;
                ix -= 3;
            }
            else break;
        }
        tans += (ix + 1) / 2;
        ans = min(ans, tans);

        if (A[n - 3] + A[n - 2] >= m) {
            tans = 1;
            ix = n - 3;
            if (A[n - 3] * 2 >= m) ix--;
            while (ix >= 2) {
                if (A[ix - 2] * 2 >= m) {
                    tans++;
                    ix -= 3;
                }
                else break;
            }
            tans += (ix + 2) / 2;
            ans = min(ans, tans);
        }

        if (n >= 4 && A[n - 1] + A[n - 4] >= m && min(A[n - 4] * 2, A[n - 2]) * 2 >= m) {
            tans = 2;
            int ix = n - 5;
            while (ix >= 2) {
                if (A[ix - 2] * 2 >= m) {
                    tans++;
                    ix -= 3;
                }
                else break;
            }
            tans += (ix + 2) / 2;
            ans = min(ans, tans);
        }
    }
    else {
        int tans = 0;
        int ix = n - 1;
        while (ix >= 2) {
            if (A[ix - 2] * 2 >= m) {
                tans++;
                ix -= 3;
            }
            else break;
        }
        tans += (ix + 2) / 2;
        ans = min(ans, tans);

    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}