#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, ans = 0;
vector<ll> A;
void search(ll l, ll r){
    if (l > r) return;
    
    ll mid = (l+r)/2;
    
    ll tp = 0;
    for (ll i : A) tp += max(0ll, i - mid);
    
    if (tp >= m) {
        ans = max(ans, mid);
        search(mid+1, r);
    }
    else search(l, mid-1);
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    A= vector<ll>(n);
    
    for (auto& i : A) cin >> i;
    
    ll r = *max_element(A.begin(), A.end());
    
    search(1, r);
    
    cout << ans;
}