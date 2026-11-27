#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> A(n+1);
    for (int i = 1; i <= n; i++){
        cin >> A[i];
        A[i] -= k;
        A[i] += A[i-1];
    }
    
    map<ll, int> cnt;
    
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans += cnt[A[i]];
        cnt[A[i]]++;
    }
    
    cout << ans;
}