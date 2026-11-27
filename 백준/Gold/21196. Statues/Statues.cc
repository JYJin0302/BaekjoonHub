#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

const ll inf = 1e15;
ll dp[5001][5001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < k; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = inf;
        }
    }
    
    vector<pair<ll, ll>> A(k);
    for(auto& i : A) cin>>i.y >> i.x;
    
    sort(A.begin(), A.end());
    
    for (int i = 1; i <= n; i++){
        dp[0][i] = min(A[0].x * abs(A[0].y - i), dp[0][i-1]);
    }
    
    for (int i = 1; i < k; i++){
        for (int j = i+1; j <= n; j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + A[i].x * abs(A[i].y - j));
        }
    }
    
    cout << dp[k-1][n];
    
}