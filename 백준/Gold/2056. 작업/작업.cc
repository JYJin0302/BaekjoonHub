#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b;
    cin >> n;
    vector<int> topo(n+1);
    vector<int> cost(n+1);
    vector<int> dp(n+1);
    vector<vector<int>> base(n+1);
    
    for (int i = 1; i <= n; i++){
        cin >> a >> b;
        cost[i] = a;
        while(b--){
            cin >> a;
            base[a].push_back(i);
            topo[i]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (topo[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        a = q.front();
        q.pop();
        dp[a] += cost[a];
        for (int k : base[a]){
            dp[k] = max(dp[k], dp[a]);
            topo[k]--;
            if(topo[k] == 0) q.push(k);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end());
    
}