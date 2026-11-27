#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
bool res[1010][1010];
 
void solve(){
 
    int n, m;
    cin >> n >> m;
 
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++) res[i][j] = 0;
    }
 
    int ans = n*m;
    for(int i =1; i <= min(n, m); i++){
        res[i][i] = 1;
        ans--;
    }
 
    if (n < m){
        for(int i = n+2; i <= m; i += 2){
            res[n][i] = 1;
            ans--;
        }
        if (n % 2 != m % 2) {
            res[n][m] = 1;
            ans--;
        }
    }
    else if(n > m){
        
        for(int i = m+2; i <= n; i += 2){
            res[i][m] = 1;
            ans--;
        }
        if (n % 2 != m % 2) {
            res[n][m] = 1;
            ans--;
        }
    }
 
    cout << ans << '\n';
    
    for(int f = 1; f <= min(n, m); f++){
        for(int i = n; i >= f; i--) if (!res[i][f]) cout << i << ' '<< f << '\n';
        for(int i = m; i >= f; i--) if (!res[f][i]) cout << f << ' '<< i << '\n';
    }
 
}
 
 
 
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
