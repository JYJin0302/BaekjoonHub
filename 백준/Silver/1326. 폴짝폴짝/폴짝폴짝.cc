#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int a, b;
    cin >> a >> b;
    a--, b--;
    
    int dist[10001];
    for(int i = 0; i < n; i++) dist[i] = -1;
    
    dist[a] = 0;
    
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        
        int x = q.front();
        q.pop();
        
        int tx = x + A[x];
        while(tx < n){
            if (dist[tx] == -1){
                dist[tx] = dist[x] + 1;
                q.push(tx);
            }
            tx += A[x];
        }
        
        tx = x - A[x];
        while(tx >= 0){
            if (dist[tx] == -1){
                dist[tx] = dist[x] + 1;
                q.push(tx);
            }
            tx -= A[x];
        }
    }
    
    cout << dist[b];
}