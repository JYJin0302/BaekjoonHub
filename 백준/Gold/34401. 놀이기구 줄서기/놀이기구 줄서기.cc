#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> lst[10];

void solve(){
    
    int n, p, k;
    cin >> n >> p >> k;

    for(int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        lst[b].push_back(a);
    }
    for(int i= 1; i <= 5; i++) {
        sort(all(lst[i]));
        reverse(all(lst[i]));
    }

    ll ans = 0;

    ll curT = 0;
    int go = 0;
    while(go < n){

        int sz = 0;
        while(sz < k){
            pair<int, int> nxt = mp(10101010, 0);
            for(int i = 1; i <= k - sz; i++){
                if (!lst[i].empty()) {
                    nxt = min(nxt, mp(lst[i].back(), i));
                }
            }
            if (nxt.y == 0) break;
            
            if (curT < nxt.x) break;
            sz += nxt.y;
            ans += curT - nxt.x;
            lst[nxt.y].pop_back();
            go++;
        }
        
        curT += p;  
    }
    cout << ans << '\n';
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