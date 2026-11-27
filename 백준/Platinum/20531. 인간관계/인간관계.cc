#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

vector<int> root;
int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

ll c[5001][5001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    vector<ll> dp(n+1);
    
    c[1][0] = 1;
    c[1][1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
        }
    }
    
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < i; j++){
           dp[i] = (dp[i] + dp[j]*c[i-1][j]) % mod;
        }
    }
    
    root = vector<int>(n+1);
    for(int i = 1; i <= n; i++) root[i] = i;
    
    int ans = n;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        find(a), find(b);
        
        if (root[a] != root[b]){
            root[root[a]] = root[b];
            ans--;
        }
        
        cout << dp[ans] << '\n';
    }
}