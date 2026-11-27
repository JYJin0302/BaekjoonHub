#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> A(n), B(n);
    for(auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int k = 0;
        for(auto j : s){
            if(j != '.') {
                k = k*10 + int(j-'0');
            }
        }   
        
        ll df1 = 0, df2 = 0;
        df1 = A[i] * k / 10 - B[i];
        df2 = A[i] - B[i] * k / 10;
        
        ans += max(df1, df2);
    }
    cout << ans;
}