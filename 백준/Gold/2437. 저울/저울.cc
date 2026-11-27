#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    
    vector<ll> base(n);
    for (auto& i : base) cin >> i;
    
    sort(base.begin(), base.end());
    
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if (base[i] - sum >= 2) {cout << sum+1; return 0;}
        sum += base[i];
    }
    cout << sum + 1;
}