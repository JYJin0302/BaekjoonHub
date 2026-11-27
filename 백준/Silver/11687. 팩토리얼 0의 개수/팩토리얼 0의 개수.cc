#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    ll l = 1, r = 1000000000;
    
    ll res = -1;
    while(l <= r){
    
        ll mid = (l+r)/2;
        
        ll val = 5;
        ll ans = 0;
        while(val <= mid){
            ans += mid / val;
            val *= 5;
        }
        
        if (ans >= n){
            r = mid - 1;
            if (ans == n) res = mid;
        }
        else l = mid + 1;
    }
    
    cout << res;
    
}