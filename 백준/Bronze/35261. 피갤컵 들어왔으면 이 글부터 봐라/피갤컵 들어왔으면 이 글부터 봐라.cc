#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
 
 
void solve(){
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
 
    string tmp = "eagle";
    int ans =5 ;
    for(int i =0 ; i<= n-5; i++){
        string ts = s.substr(i, 5);
 
        int cnt = 0;
        for(int j=0 ;j < 5;j ++){
            if (tmp[j] != ts[j]) cnt++;
        }
        ans =min(ans, cnt);
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
