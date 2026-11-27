#include <bits/stdc++.h>
using namespace std;

vector<int> ran[103];
int pr[103];
int t[103];
int dp[103];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int mr = 1;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        
        pr[i] = a;
        ran[a].push_back(i);
        t[i] = b;
        
        mr = max(mr, a);
    }
    
    queue<int> q;
    for (int i : ran[1]) q.push(i);
    
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        int cr = pr[a];
        for (int i : ran[cr+1]){
            dp[i] = max(dp[i], dp[a] + t[a] + (i-a)*(i-a));
        }
        
        if (q.empty()){
            for (int i : ran[cr+1]) q.push(i);
        }
    }
    
    int ans = 0;
    for (int i : ran[mr]){
        ans = max(ans, dp[i] + t[i]);
    }
    cout << ans;
    
}