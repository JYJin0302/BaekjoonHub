#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll cnt0[333];
ll cnt1[333][333];
ll cnt2[333][333];


void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    for(auto f : A){


        for(int i=0 ; i + f < 300; i++){
            (cnt2[i][f] += cnt2[i+f][i] + cnt1[i+f][i]) %= mod;
        }

        for(int i = 0; i < 300; i++){
            (cnt1[i][f] += cnt0[i]) %= mod;
        }
        cnt0[f]++;

    }
    ll ans = 0;
    for(int i =0 ;i < 300; i++){
        for(int j = 0;j < 300; j++){
            ans = (ans + cnt2[i][j]) % mod;
        }
    }
    cout << ans << '\n';



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