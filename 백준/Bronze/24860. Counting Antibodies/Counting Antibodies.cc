#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    ll v1, j1, v2, j2;
    cin >> v1 >> j1 >> v2 >> j2;

    ll val1 = v1* j1 + v2 * j2;


    ll a, b, c;
    cin >> a>> b>> c;
    ll val2 = a * b * c;
    cout << val1 * val2 << '\n';
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

