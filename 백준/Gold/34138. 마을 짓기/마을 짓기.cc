#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

char G[2020][2020];
int cnt1[2020][2020];
int cnt2[2020][2020];

int getS(int x1, int y1, int x2, int y2){
    return cnt2[x2][y2] - cnt2[x1-1][y2] - cnt2[x2][y1-1] + cnt2[x1-1][y1-1];
}

void solve() {

    int n, m;
    cin >> n >> m;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> G[i][j];
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(G[i][j] == 'X'){
                cnt1[i][j] = 1 + cnt1[i-1][j-1];
            }
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(G[i][j] == '.'){
                cnt2[i][j] = 1;
            }
            cnt2[i][j] += cnt2[i-1][j] + cnt2[i][j-1] - cnt2[i-1][j-1];
        }
    }

    int sz = min(n, m);
    vector<ll> ans(sz+10);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int len = min(i, j);

            int res = 0;
            int l =  1, r = len;
            while(l <= r){
                int md= (l+r)>>1;
                if (getS(i-md+1, j-md+1, i, j) == md*md - md && cnt1[i][j] >= md){
                    res = md;
                    l = md + 1;
                }
                else r = md - 1;
            }
            ans[1]++;
            ans[res + 1]--;
        }
    }

    for(int i = 1; i <= sz; i++){
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }
    cout << '\n';
    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}