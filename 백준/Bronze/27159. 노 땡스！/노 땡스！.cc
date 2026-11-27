#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void solve() {

    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int ans = A[0];
    for(int i = 1; i < n; i++){
        if(A[i] - A[i-1] != 1) ans += A[i];
    }
cout << ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}