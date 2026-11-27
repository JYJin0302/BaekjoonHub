#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e10;

int n, m;
ll dist[1001];
ll cost[1001];
ll cS[1001];

ll dp[1001][1001][2];

ll solve(int l, int r, bool p){
    // l, r 범위, p : 1->오른쪽, 0-> 왼쪽
    
    int currPos = l;
    if (p) currPos = r;
    
    if (dp[l][r][p] != INF) return dp[l][r][p];
    
    if (l == 1 && r == n) return dp[l][r][p] = 0;
    
    // 이동하는 시간만큼 [l, r] 밖의 가로등은 전력을 소모한다
    ll val = INF;
    
    ll totM = cS[n] - cS[r] + cS[l-1];
    if (l > 1){
        ll dst = dist[currPos] - dist[l-1];
        val = min(val, totM*dst + solve(l-1, r, 0));
    }
    
    if (r < n){
        ll dst = dist[r+1] - dist[currPos];
        val = min(val, totM*dst + solve(l, r+1, 1));
    }

    return dp[l][r][p] = val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        cin >> dist[i] >> cost[i];
        
        cS[i] = cS[i-1] + cost[i];
    }
    
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }
    
    cout << solve(m, m, 0);
}