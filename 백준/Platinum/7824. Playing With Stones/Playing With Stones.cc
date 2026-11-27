#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll getG(ll x){
    while(x & 1) x>>= 1;
    return (x >> 1);
}

void solve(){
    
    int n;
    cin >>n;

    ll x = 0;
    for(int i =0 ;i  < n; i++){
        ll v;
        cin >> v;
        x ^= getG(v);
    }

    if (x) cout << "YES\n";
    else cout << "NO\n";
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // for(int j =  1; j <= 32; j++){
    //     cout << getG(j) << ' ';
    // }
    // cout << '\n';


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
