#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
void solve(){
     
    string s;
    cin >> s;
 
    int val = 0;
    int ans = 0;
    string ansS;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'C'){
            if (val + 1 <= (int)s.size() - i - 1) val++, ansS+='(';
            else val--, ans += 2, ansS += ')';
        }
        else{
            ans++;
            if(val == 0) ansS += '(';
            else ansS += ')';
            val = abs(val - 1);
        }
    }
 
    assert(val == 0);
    cout << ans << '\n' << ansS << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) solve();
}
