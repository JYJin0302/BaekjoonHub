#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    vector<int> dist((1 << k), -1);
    
    queue<int> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        int val = 0;
        for(int j = 0; j < k; j++){
            if (s[j] == '1') val += (1 << j);
        }
        q.push(val);
        dist[val] = 0;
    }
    
    int ans = -1;
    while(!q.empty()){
        int a = q.front();
        ans = a;
        q.pop();
        
        for(int i = 0; i < k; i++){
            int na = a ^ (1 << i);
            if (dist[na] == -1){
                dist[na] = dist[a] + 1;
                q.push(na);
            }
        }
    }
    
    for(int i = 0; i < k; i++){
        if(ans & (1 << i)) cout << 1;
        else cout << 0;
    }
    
}
