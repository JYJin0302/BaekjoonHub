#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {
    
    int n;
    cin >> n;

    int val = 12 * 2024 + 7;
    val += (n-1) * 7;
    cout << val / 12 << ' ' << val% 12 + 1 << '\n';
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}