#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


void solve(){

    ll a, b;
    cin >> a>> b;
    if (a == b) {
        cout << a<< '\n';
        return;
    }

    ll res = 0;
    for(ll i = 61; i >= 0; i--){
        ll v = 1ll << i;

        bool a1 = a & v;
        bool b1 = b & v;
        if(a1 == b1) continue;

        ll tval = (b >> (i+1)) << (i+1);
        if(tval >= a) {
            res = tval;
            break;
        }

        for(int j = i; j >= 0; j--){
            if (tval + (1ll << j) >= a) {
                res = tval + (1ll << j);
            }
        }
        break;
    }
    cout << res << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}