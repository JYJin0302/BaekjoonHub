#include <bits/stdc++.h>
using namespace std;

int n, a;
vector<vector<int>> base;
vector<int> dp;

void dfs(int v = 0, int p = 0){
    priority_queue<int> pq;
    for (int i : base[v]){
        if (i == p) continue;
        dfs(i, v);
        pq.push(dp[i]);
    }
    int t = 0;
    int cnt = 0;
    while(!pq.empty()){
        cnt++;
        a = pq.top(); pq.pop();
        t = max(t, a + cnt);
    }
    dp[v] = t;
}


int main(){
    cin >> n;
    
    base = vector<vector<int>> (n);
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a != -1){
            base[a].push_back(i);
        }
    }
    dp = vector<int> (n);
    
    dfs();
    cout << dp[0];
}