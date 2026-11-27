#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


 

void solve() {

    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        A[i] = c - '0';
    }
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        B[i] = c - '0';
    }

    vector<int> dp(10);
    for (int i = 0; i < 10; i++) dp[i] = i;

    for (int i = 0; i < n; i++) {

        vector<int> tmp(10, n* 100);
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int nv = (A[i] + j + k) % 10;
                nv = (10 + nv - B[i]) % 10;
                tmp[(j + k) % 10] = min(tmp[(j + k) % 10], dp[j] + k + nv);
            }
        }
        swap(tmp, dp);
    }
    cout << *min_element(all(dp));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}