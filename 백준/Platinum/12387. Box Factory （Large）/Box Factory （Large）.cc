#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> idxLstA[101], idxLstB[101];
ll dp[101][101];
int tcnt = 0;

void solve() {    
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> A(n), B(m);
    for(auto&[a,b]: A) cin >> a >> b;
    for(auto&[a,b]: B) cin >> a >> b;

    for(int i = 1; i <= 100; i++){
        idxLstA[i].clear();
        idxLstB[i].clear();
    } 

    for(int i =0; i < n;i++){
        idxLstA[A[i].y].push_back(i);
    }
    for(int j =0;j < m;j++){
        idxLstB[B[j].y].push_back(j);
    }
    for(int i =0 ; i <= n ;i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < m; j++){
            if(A[i].y == B[j].y){
                ll nval = (i && j ? dp[i-1][j-1] : 0ll);

                int i1 = lower_bound(all(idxLstA[A[i].y]), i) - idxLstA[A[i].y].begin();
                ll val1 = A[i].x;
                int j1 = lower_bound(all(idxLstB[B[j].y]), j) - idxLstB[B[j].y].begin();
                ll val2 = B[j].x;

                while(i1 < idxLstA[A[i].y].size() && j1 < idxLstB[B[j].y].size()){
                    ll addVal = min(val1, val2);
                    nval += addVal;
                    int ix1 = idxLstA[A[i].y][i1];
                    int ix2 = idxLstB[B[j].y][j1];
                    dp[ix1][ix2] = max(dp[ix1][ix2], nval);

                    val1 -= addVal;
                    val2 -= addVal;
                    
                    if (val1 == 0){
                        i1++;
                        if (i1 < idxLstA[A[i].y].size()){
                            val1 = A[idxLstA[A[i].y][i1]].x;
                        }
                    }
                    if (val2 == 0){
                        j1++;
                        if (j1 < idxLstB[B[j].y].size()){
                            val2 = B[idxLstB[B[j].y][j1]].x;
                        }
                    }
                }
            }
            
            if (i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout << "Case #" << ++tcnt << ": " << dp[n-1][m-1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}