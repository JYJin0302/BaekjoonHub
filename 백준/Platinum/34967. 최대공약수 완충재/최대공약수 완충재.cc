#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    int n;cin >> n;
    const int lim = 1e8;
    vector<ll> A;
    A.push_back(80000000);
    A.push_back(40000000);
    A.push_back(20000000);
    A.push_back(10000000);

    int l = 2, r = 19997;

    
    for(int p = 1 ; (int)A.size() < n && l <= r; p ^= 1){
        ll val = 1ll * l * r / gcd(l, r);
        A.push_back(val);
        
        if (p) l++;
        else r--;
    }

    
    for(int i =0 ; i< n;i++) cout << A[i] << ' ';
    cout << '\n';
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
