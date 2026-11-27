#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

void solve(){
    
    int n;
    cin >> n;

    ll ans = 0;
        
    for(int g = 1; g <= n; g++){
        if (n % g == 0){
            for(int i = 1; i * 2 <= n/g + 1; i++){
                if (gcd(i, n/g+1) == 1) ans++;
            }
        }
    }
    cout << ans << '\n';

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
