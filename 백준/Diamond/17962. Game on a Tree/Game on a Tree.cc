#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[100010];
vector<int>adj[100010];

void dfs(int v, int pv = -1){

    for(auto i :adj[v])if (i != pv){
        dfs(i, v);
        dp[v] += dp[i];
    }

    if(dp[v] == 0)dp[v] = 1;
    else dp[v]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >>n;

    for(int i = 0; i <n-1; i++){
        int a, b;
        cin >>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    if (dp[1]) cout <<"Alice";
    else cout <<"Bob";
}
