#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    ll ans = 0;

    vector<int> cnt(101010);
    int l = 0;
    for (int i = 0; i < n; i++) {
        cnt[A[i]]++;

        while (l < i && cnt[A[i]] >= 2) {
            cnt[A[l]]--;
            l++;
        }
        ans += i - l + 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}