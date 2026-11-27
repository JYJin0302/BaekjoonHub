#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() { 
    
    ll n, t;
    cin >> n >> t;

    vector<ll> A(n);
    for(auto& i : A) {
        cin >> i;
        i %= t;
    }
    sort(all(A));

    ll mn = A.back() - A[0];
    for(int i = 1; i < n; i++){
        mn = min(mn, A[i-1] + t - A[i]);
    }

    cout << (mn + 1) / 2 << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
