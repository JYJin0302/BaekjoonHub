#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;

    vector<int> ans(n, 1);
    for(int i = 0; i < n-1; i++){
        int ix = 0;
        while(ix < n ){
            int d = ans[ix] + 1;
            ans[ix]++;
            ix += d;
        }

        // for(auto f : ans) cout << f << ' ';
        // cout << '\n';

    }

    // ll aa = 0;
    // for(auto f : ans) aa += f;
    // cout << aa << '\n';

    for(auto f : ans) cout << f << ' ';
    cout << '\n';

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