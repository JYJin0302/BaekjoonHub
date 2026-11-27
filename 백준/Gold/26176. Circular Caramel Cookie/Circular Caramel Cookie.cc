#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    ll s;
    cin >> s;

    s =  s / 4 + 1;

    double L = 1, R = 20000, ans = R;
    while(R - L > 1e-7){
        double md = (L+R)/2;

        ll tot = 0;
        int lim = floor(md);
        for(ll i =1 ; i <= lim; i++){
            tot += floor(sqrtl(md *md - i*i));
        }
        if(tot >= s){
            ans = md;
            R = md;
        }
        else L = md;
    }

    cout << setprecision(15);
    cout << ans << '\n';
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}

