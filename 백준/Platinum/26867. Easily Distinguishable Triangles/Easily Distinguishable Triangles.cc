#include<bits/stdc++.h>
using ll = long long;
using namespace std;

char A[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memset(A, '.', sizeof(A));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> A[i][j];
    }

    const ll mod = 998244353;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        
        int ix = 1;
        while (ix <= n) {
            while (ix <= n && A[i][ix] != '?') ix++;
            int l = ix;
            while (ix <= n && A[i][ix] == '?') ix++;
            int r = ix;

            if (A[i][l - 1] == '#' && A[i][r] == '#') ans *= 0;
            else if (A[i][l - 1] == '.' && A[i][r] == '.') ans = ans * (r - l + 1) % mod;
        }
    }

    for (int i = 1; i <= n; i++) {

        int ix = 1;
        while (ix <= n) {
            while (ix <= n && A[ix][i] != '?') ix++;
            int l = ix;
            while (ix <= n && A[ix][i] == '?') ix++;
            int r = ix;

            if (A[l-1][i] == '#' && A[r][i] == '#') ans *= 0;
            else if (A[l-1][i] == '.' && A[r][i] == '.') ans = ans * (r - l + 1) % mod;
        }
    }

    cout << ans;
}
