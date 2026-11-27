#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    ll c = 1;
    vector<pair<ll, ll>> A(n);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        
        int cnt3 = 0, cnt2 = 0;
        while(x % 3 == 0) cnt3++, x/=3;
        while(x % 2 == 0) cnt2++, x/=2;
        
        c = x;
        A[i] = {cnt3, -cnt2};
    }
    
    sort(A.rbegin(), A.rend());
    for(auto i : A){
        int a, b;
        tie(a, b) = i;
        
        b *= -1;
        ll res = c;
        while(a--) res *= 3;
        while(b--) res *= 2;
        cout << res << ' ';
    }
}