#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, a;
        cin >> n;
        
        vector<vector<int>> A(n+1);
        vector<int> topo(n+1);
        
        for (int i = 1; i <= n; i++){
            cin >> a;
            A[i].push_back(a);
            topo[a]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++){
            if (topo[i] == 0) q.push(i);
        }
        
        int ans = 0;
        while(!q.empty()){
            a = q.front();
            q.pop();
            ans++;
            for (int i : A[a]){
                topo[i]--;
                if (topo[i] == 0) q.push(i);
            }
        }
        cout << ans << '\n';
    }
}