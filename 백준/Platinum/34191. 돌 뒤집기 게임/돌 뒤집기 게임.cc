#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
void solve() {
 
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    vector<int> cnt(5);
    
    int ix = 0;
    while(ix < n){
        while(ix < n && s[ix] == 'T') ix++;
        int len  = 0;
        while(ix < n && s[ix] == 'H') ix++, len++;
 
        if (len >= 5 || len == 3){
            cout << "First\n";
            return;
        }
        cnt[len]++;
    }
    
    int tot = (cnt[1] + cnt[4]) % 2;
    if (tot) cout << "First\n";
    else cout << "Second\n";
    
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
