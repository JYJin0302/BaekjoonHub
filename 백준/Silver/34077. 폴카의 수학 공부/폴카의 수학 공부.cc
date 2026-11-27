#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ix = 0;
    while(ix < n*2+1 && s[ix] != '-'){
        ix++;
    }
    if (ix == n*2+1){
        cout << "YES\n";
        return;
    }

    ix += 3;
    while(ix < n*2+1){
        if (s[ix] != '0') {
            cout << "NO\n";
            return;
        }
        ix += 2;
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}