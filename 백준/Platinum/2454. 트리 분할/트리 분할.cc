#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300001];
int dp[300001];

int n, k;
int ans = 0;
void dfs(int v, int pv = -1){
    
    vector<int> tmp;
    for (auto i : adj[v]) if (i != pv){
        dfs(i, v);
        if (dp[i] != 0) tmp.push_back(dp[i]);
    }
    
    sort(tmp.begin(), tmp.end());
    
    if (tmp.empty()) dp[v] = 1;
    else if (tmp.size() == 1) {
        dp[v] = tmp[0] + 1;
        if (dp[v] == k) {
            ans++;
            dp[v] = 0;
        }
    }
    else{
        
        if (tmp[0]+tmp[1]+1 <= k){
            dp[v] = 0;
            ans += tmp.size() - 1;
        }
        else{
            dp[v] = tmp[0] + 1;
            ans += tmp.size() - 1;
            if (dp[v] == k) {
                ans++;
                dp[v] = 0;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    k++;
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    cout << ans + (dp[1] != 0);
}