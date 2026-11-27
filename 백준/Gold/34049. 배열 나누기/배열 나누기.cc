#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair



void solve(){
    
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    int ans = 0;
    ll cur = 0;
    for(int i = n-1; i >= 0; i--){
        cur += A[i];
        if (cur >= 0){
            ans++;
            cur = 0;
        }
        else{

        }
    }
    if (cur < 0){
        cout << -1 << '\n';
    }
    else cout << ans << '\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
