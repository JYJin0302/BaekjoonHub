#include <bits/stdc++.h>
using namespace std;

int ans;
vector<vector<int>> adj;
vector<bool> check;
void dfs(int n){
    for (int i : adj[n]){
        if (check[i]) continue;
        check[i] = true;
        ans++;
        dfs(i);
    }
}



int main(){
    int n, t, n1, n2;
    cin >> n >> t;
    adj = vector<vector<int>>(n+1);
    check = vector<bool> (n+1);
    while(t--){
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    ans = 0;
    check[1] = true;
    dfs(1);
    cout << ans;
}