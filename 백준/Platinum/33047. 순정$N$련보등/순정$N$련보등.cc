#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for (auto& i : A) cin >> i;

    vector<int> dp(n + k + 10);
    vector<ll> costDp(n + k + 10);
    ll cost = 0;
    ll dif = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(A[i + 2] - (i + 1));

        //cout << "Pre: " << i+2 << " " << A[i + 2] << " : ";
        if (A[i + 2] >= i + 1) {
            dif++;// cout << 2 << ' ' << "+1 ";
            dp[i + 3] -= A[i + 2];// cout << i + 3 << ' ' << "-" << A[i + 2] << ' ';
            dp[i + 4] += A[i + 2] - 1;// cout << i + 4 << ' ' << "+" << A[i + 2] - 1<< ' ';
        }
        else {
            int t = i + 1 - A[i + 2];
            dif--; //cout << 2 << ' ' << "-1 ";
            dp[2 + t + 1] += 2;// cout << 2 + t + 1 << ' ' << "+" << 2 << ' '; 
            dp[i + 3] -= A[i + 2];// cout << i + 3 << ' ' << "-" << A[i + 2] << ' ';
            dp[i + 4] += A[i + 2] - 1;// cout << i + 4 << ' ' << "+" << A[i + 2] - 1<< ' ';
        }
       // cout << '\n';
    }
    costDp[2] = cost;

    for (int i = 3; i + n <= k - 2; i++) {
        dif += dp[i];
        cost += dif;

        cost += abs(A[i + n - 1] - n);

       // cout << "process : " << i << " " << A[i + n - 1] << " | ";
        int t = n - A[i + n - 1];
        dif--;// cout << i << ' ' << "-1 ";
        dp[i + t + 1] += 2;// cout << i + t + 1 << ' ' << "+" << 2 << ' ';
        dp[i + n] -= A[i + n - 1];// cout << i  + n << ' ' << "-" << A[i + n - 1]<< ' ';
        dp[i + n + 1] += A[i + n - 1] - 1; //cout << i  + n + 1 << ' ' << "+" << A[i + n - 1] - 1<< ' ';
        //cout << '\n';

        costDp[i] = cost;
    }

    ll ans = 1e18;
    for (int i = 2; i + n <= k - 2; i++) {
        ll tans = costDp[i];
        tans += abs(1 - A[i - 2]) + abs(1 - A[i - 1]);
        tans += abs(n - A[i + n]) + abs(n - A[i + n + 1]);
        ans = min(ans, tans);
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}