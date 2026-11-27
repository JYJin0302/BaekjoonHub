#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[1001010];
int dp[1001010];
char C[1001010];

int totA = 0, totB = 0;

void dfs(int v){
    if (C[v] == 'G'){
        for(auto f: adj[v]){
            dfs(f);
            if (C[f] == 'G') continue;

            if (C[f] == 'R' && dp[f] > 0) totA += dp[f];
            if (C[f] == 'B' && dp[f] < 0) totB += -dp[f];
        }
    }
    else if(C[v] == 'R'){
        int ret = 1;
        for(auto f : adj[v]){
            dfs(f);
            if (C[f] == 'G') continue;

            if (C[f] == 'B') ret += min(0, dp[f]);
            else ret += max(0, dp[f]);
        }

        dp[v] = ret;
    }   
    else{
        int ret = -1;
        for(auto f : adj[v]){
            dfs(f);
            if (C[f] == 'G') continue;

            if (C[f] == 'R') ret += max(0, dp[f]);
            else ret += min(0, dp[f]);
        }

        dp[v] = ret;
    }
    
}

void solve(){
    
    int n;
    cin >> n;

    for(int i =2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for(int i =1; i <= n; i++) cin >> C[i];
    dfs(1);

    //cout << totA << ' ' << totB << '\n';

    cout << max(0, totB - totA) << '\n';
    
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