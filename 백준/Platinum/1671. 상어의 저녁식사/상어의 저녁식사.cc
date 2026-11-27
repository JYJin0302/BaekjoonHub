#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int match[101], co[101];

bool dfs(int l){
    if (co[l]) return 0;
    co[l] = 1;
    
    for (auto i : adj[l]){
        if (match[i] == -1 || dfs(match[i])){
            match[i] = l;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> A(n);
    for(int i = 0; i < n; i++){
        int a, b,c;
        cin >> a >>b >> c;
        A[i] = {a, b, c};
    }
    
    for (int i = 0; i < n*2; i++) match[i] = -1;
    
    for (int i = 0; i < n; i++){
        int a, b, c;
        tie(a, b, c) = A[i];
        for (int j = i +1 ; j < n; j++){
            int x, y, z;
            tie(x, y, z) = A[j];
            
            if (a >= x && b >= y && c >= z) {
                adj[i*2].push_back(j);
                adj[i*2+1].push_back(j);
            }
            else if (x >= a && y >= b && z >= c) {
                adj[j*2].push_back(i);
                adj[j*2+1].push_back(i);
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n*2; i++){
        memset(co, 0, sizeof(co));
        cnt += dfs(i);
    }
    
    cout << n - cnt;
}