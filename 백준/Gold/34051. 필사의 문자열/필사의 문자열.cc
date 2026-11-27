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
    string s;
    cin >> n >> s;

    vector<int> suf(n);
    for(int i = n-1 ; i >= 0; i--){
        suf[i] = s[i] - 'a';
        if (i != n-1) suf[i] = max(suf[i], suf[i+1]);
    }

    int ix =  0;
    while(ix < n && suf[ix] + 'a' == s[ix]) ix++;

    string ans = s;
    if (ix != n){
        for(int j = ix + 1;j < n; j++){
            if (s[j] == suf[ix] + 'a'){
                string tmp = s.substr(0, ix);
                for(int k = j; k >= ix; k--) tmp += s[k];
                for(int k = j + 1; k < n; k++) tmp += s[k];
                ans = max(ans, tmp);
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
