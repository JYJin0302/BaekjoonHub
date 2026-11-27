#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

ll k, h, q;
ll dp[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> h >> q;;

    for (int i = 1; i <= h; i++) {
        dp[i] = dp[i - 1] * (k + 1) + k;
    }
    k++;

    ll mx = dp[h];
    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        if (b > mx) {
            cout << -1 << '\n';
            continue;
        }
        if (a == b) {
            cout << "0\n";
            continue;
        }

        vector<int> A, B;
        for (int i = 0; i <= h; i++) {
            A.push_back(a % k); a /= k;
            B.push_back(b % k); b /= k;
        }

        int ans = 0;

        int ax = 0, bx = 0;
        while (ax < h && A[ax] == 0) ax++;
        while (bx < h && B[bx] == 0) bx++;

        int ix = h - 1;
        while (ix > max(ax,bx) && A[ix] == B[ix]) ix--;

        ans = (ix + 1) * 2 - ax - bx;
        cout <<  ans << '\n';

    }


}