#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2001];
bool visited[2001];

int cnt1 = 0, cnt2 = 0;
void dfs(int v, int pv, bool p){
    cnt1++;
    cnt2 += p;
    for(auto i :adj[v]) if(!visited[i]){
        visited[i] = 1;
        dfs(i, v, 1^p);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n ;i++){
        string s;
        cin >> s;
        
        for (int j = 0; j < n; j++){
            if (s[j] == '1') {
                adj[i].push_back(j+1);
                adj[j+1].push_back(i);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]) {
            cnt1 = 0, cnt2 = 0;
            visited[i] = 1;
            dfs(i, 0, 1);
            
            ans += max(cnt1 - cnt2, cnt2);
        }
    }
    
    cout << ans;
    
}