#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<bool> vis(n);
    vis[0] =1 ;
    for(int i = 1; i < n; i++){
        if (s[i] == '#') {}
        else{
            if (vis[i-1] || (i-k >= 0 && vis[i-k])) vis[i] = 1;
        }
    }
    
    if (vis[n-1]) cout << "YES\n";
    else cout << "NO\n";
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