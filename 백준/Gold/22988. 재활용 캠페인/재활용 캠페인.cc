#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    int ans = 0;
    int l = 0, r = n-1;
    while(r >= 0 && A[r] == m){
        ans++;
        r--;
    }
    
    int cnt = 0;
    while(l < r){
        if ((A[l] + A[r]) >= (m+1)/2){
            ans++;
            l++, r--;
        }
        else{
            cnt++;
            l++;
        }
    }
    ans += (cnt+(l==r)) / 3;
    
    cout << ans;
}