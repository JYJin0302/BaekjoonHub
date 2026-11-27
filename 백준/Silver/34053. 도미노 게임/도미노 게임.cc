#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

ll G[2020][2020];

void solve(){

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        for(int j =0 ; j < m; j++){
            cin >> G[i][j];
        }
    }

    ll mn = G[0][0];
    ll tot = 0;
    for(int i = 0; i < n;i++){
        for(int j =0 ;j < m;j++){
            mn = min(mn, G[i][j]);
            tot += G[i][j];
        }
    }

    cout << tot - mn << '\n';
    
    

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
