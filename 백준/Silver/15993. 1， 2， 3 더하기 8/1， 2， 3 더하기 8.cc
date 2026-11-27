#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    
    ll mod = 1e9 + 9;
    
    vector<pair<ll, ll>> base(100001);
    base[1] = {1, 0};
    base[2] = {1, 1};
    base[3] = {2, 2};
    
    for (int i = 4; i <= 100000; i++){
        base[i] = {(base[i-1].second + base[i-2].second + base[i-3].second)%mod, (base[i-1].first + base[i-2].first+base[i-3].first)%mod};
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << base[n].first << ' ' << base[n].second << '\n';
    }
}