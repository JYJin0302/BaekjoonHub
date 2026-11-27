#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {    
    vector<int> A(5);
    for (auto& i : A) cin >> i;
    sort(all(A));

    int ans = 0;
    for (auto f : A) ans += f;
    ans /= 5;
    cout << ans << '\n' << A[2] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}