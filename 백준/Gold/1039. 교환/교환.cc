#include <bits/stdc++.h>
using namespace std;

bool v[1000001][2];

void solve(int n, int k){
    
    v[n][k%2] = 1;
    
    queue<pair<int, int>> q;
    q.push({n, k});
    while(!q.empty()){
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        b--;
        string s = to_string(a);
        int m = s.size();
        
        for (int i = 0; i < m; i++){
            for (int j= i+1; j < m; j++){
                if (i != 0 || s[j] != '0'){
                    swap(s[i], s[j]);
                    int tp = stoi(s);
                    if(!v[tp][b%2]){
                        v[tp][b%2] = 1;
                        if (b != 0) q.push({tp, b});
                    }
                    swap(s[i], s[j]);
                }
            }
        }
        
    }
    
    
}


int main(){
    
    int n, k;
    cin >> n >> k;
    
    if (n < 10 || (n < 100 && n % 10 == 0)){
        cout << -1;
        return 0;
    }
    
    solve(n, k);
    
    int ans = -1;
    for (int i = 1; i <= 1000000; i++){
        if (v[i][0]) ans = max(ans, i);
    }
cout << ans;
    
}