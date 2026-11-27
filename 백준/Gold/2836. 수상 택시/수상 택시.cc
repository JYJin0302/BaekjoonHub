#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n, m, a, b;
    cin >> n >> m;
    
    vector<pair<ll ,ll>> A;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (a > b) A.push_back({b, a});
    }
    sort(A.begin(), A.end());
    
    ll ans = 0;
    ll l = 0, r = 0;
    for (auto i : A){
        tie(a, b) = i;
        if (a <= r) r = max(r, b);
        else {
            ans += r-l;
            l = a;
            r = b;
        }
    }
    
    ans += r - l;
    
    cout << m + 2*ans;
}