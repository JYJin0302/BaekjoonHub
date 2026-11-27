#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

ll B = 0;
int qCnt = 0;
ll ask(ll v){
    cout << "? " << v << endl;
    qCnt++;
    ll res;
    cin >> res;
    return res;
}

void solve(){
    
    ll cur = 1;
    ll ans = 0;
    while(1){
        ll res = ask(cur);

        if (res == cur){}
        else {
            ans = cur - res;
            break;
        }
        cur <<= 1;
    }

    cout << "! " << ans << endl;   
   // cout << qCnt << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}