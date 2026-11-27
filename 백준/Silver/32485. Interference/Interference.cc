#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n, w;
    cin >> n >> w;

    vector<array<int, 3>> Q;

    vector<ll> ans;

    for(int i =0 ;i < n; i++){
        char c;
        cin >> c;
        if (c == '?'){
            int x;
            cin >> x;
            
            ll res = 0;
            for(auto f : Q){
                int L = f[0];
                int R = L + f[1] - 1;
                if (L <= x && x <= R){
                    int off = (x - L ) % 4;
                    if (off == 0) res += f[2];
                    else if (off == 2) res -= f[2];
                }
            }
            ans.push_back(res);
        }
        else{
            int a, b, d;
            cin >> a >> b >> d;
            Q.push_back({a, b, d});
        }
    }

    for(auto f: ans) cout <<f << '\n';




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
