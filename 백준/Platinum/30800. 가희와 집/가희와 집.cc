#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll G[3030][3030];


void solve(){
    
    int n, m;
    cin >> n >> m;

    int w1, w2, h1, h2;
    cin >> h1 >> h2 >> w1 >> w2; 
    h1++, h2++, w1++, w2++;

    for(int i = 1; i <= n; i++){
        for(int j =1;j <= m; j++){
            cin >> G[i][j];
            G[i][j] += G[i-1][j] + G[i][j-1] - G[i-1][j-1];
        }
    }

    ll ans = 1e18;
    for(int h = h1; h <= min(n, h2); h++){
        deque<pair<ll, ll>> dq;

        for(int j = w1; j <= m; j++){
            ll tval = G[h][j-w1] + G[1][j-w1+1] - G[h-1][j-w1+1];
            while(!dq.empty() && dq.back().x <= tval){
                dq.pop_back();
            }
            dq.push_back(mp(tval, j-w1));

            while(!dq.empty() && dq.front().y < j - w2) dq.pop_front();

            ll val = G[h][j] + G[1][j-1] - G[h-1][j-1] - dq.front().x;

            //cout << "Got: " << h << ' '<< j << ' ' << dq.front().y << " => " << val << '\n';
            ans = min(ans, val);
        }
    }

    if (ans > (ll)1e17){
        cout << "No\n";
    }
    else cout << ans << '\n';

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

