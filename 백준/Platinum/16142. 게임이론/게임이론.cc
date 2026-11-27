#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> adj[50001];
bool visited[50001];
int cnt = 0;

void dfs(int v, int pv = -1){
    visited[v] = 1;
    if (A[v] > 1) return;
    cnt++;
    
    for(auto i : adj[v]) if (i != pv && !visited[i]) {
        dfs(i, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
    int cnt1 = 0;
    
    A = vector<int>(n);
    for(auto& i : A) {
        cin >> i;
        cnt1 += (i == 1);
    }
    
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a != b){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    
    if (cnt1 == n){
        if (n % 2 == 1) cout << "hwy";
        else cout << "sjh";
        return 0;
    }
    
    dfs(s);
    
    if(cnt % 2 == 0) cout << "hwy";
    else cout << "sjh";
}