#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int sMax[202020];
int pMin[202020];
int pos[202020];
int pp[202020];
int sCnt[202020];
int pMax[202020];

void solve(){
    
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(auto& [a, b] : A) cin >> a>> b;

    vector<int> xnum, ynum;
    for(auto[a,b] : A){
        xnum.push_back(a);
        ynum.push_back(b);
    }
    sort(all(xnum));
    sort(all(ynum));
    for(auto&[a,b]: A){
        a = lower_bound(all(xnum), a) - xnum.begin() + 1;
        b = lower_bound(all(ynum), b) - ynum.begin() + 1;
    }
    sort(all(A));

    ll ans = 0;   
    for(int i = 0; i < n ;i++){
        pMin[i] = A[i].y;
        pMax[i] = A[i].y;
        if (i) {
            pMin[i] = min(pMin[i], pMin[i-1]);
            pMax[i] = max(pMax[i], pMax[i-1]);
        }
    }
    
    for(int i = n-1; i >= 0; i--){
        sMax[i] = A[i].y;
        if (i != n-1) sMax[i] = max(sMax[i], sMax[i+1]);
    }
    for(int i = n-1; i >= 0; i--){
        if (A[i].y == sMax[i]) sCnt[i] = 1;
        else sCnt[i] = 0;
        sCnt[i] += sCnt[i+1];
    }

    for(auto[a, b]: A) pos[b] = a;
    for(int i =1; i <= n; i++){
        pp[i] = max(pos[i], pp[i-1]);
    }

    // for(auto[a,b]: A) cout <<b << ' ';
    // cout << '\n';
    // for(int i =1; i <= n; i++) cout << pp[i] << ' ';
    // cout << '\n';

    for(int i = 0; i < n; i++){
        if (pMin[i] == A[i].y){
            // Left down
            int v = pMax[i];
            int r = pp[A[i].y];
            if (r >= n) continue;

            // r ~ n-1까지 
            int iter = -1;
            int L = 0, R = n-1;
            while(L <= R){
                int md = (L+R)>>1;
                if (sMax[md] >= v) {
                    L = md + 1;
                }
                else{
                    iter = md;
                    R = md -1 ;
                }
            }
          //  cout << "GO : "<< i << ' ' << r << ' ' << iter << '\n';
            int res = sCnt[r];
            if (iter != -1) res -= sCnt[iter];
            ans += max(0, res);
        }
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