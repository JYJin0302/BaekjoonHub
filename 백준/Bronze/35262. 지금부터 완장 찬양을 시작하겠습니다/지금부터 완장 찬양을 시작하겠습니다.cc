#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
 
 
void solve(){
    
    int n, k;
    cin >> n >> k;
 
    string s;
    cin >> s;
    int cnt = 0;
    bool ok = 1;
    for(int i =0 ;i < n; i++){
        if (s[i] == '0'){
            cnt++;
            if (cnt >= k) ok = 0;
        }
        else cnt = 0;
    }
 
    cout << ok << '\n';
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
