#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n;
int cost[16][16];
int dp[1 << 16];
string s;

int solve(int x){
    if (dp[x] != -1) return dp[x];
    if (x == 0) return dp[x] = inf;
    
    int res = inf;
    
    vector<int> tmp;
    for(int i = 0; i < n; i++){
        if (x & (1 << i)) tmp.push_back(i);
    }
    
    int sz = tmp.size();
    
    for(int i = 0; i < sz; i++){
        x ^= (1 << tmp[i]);
        for (int j = 0; j < sz; j++){
            res = min(res, solve(x) + cost[tmp[j]][tmp[i]]);
        }
        x ^= (1 << tmp[i]);
    }
    return dp[x] = res;
}

int main(){
    
    cin >> n;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n ;i++){
        for (int j=0; j < n; j++){
            cin >> cost[i][j];
        }
    }
    
    
    cin >> s;
    
    int k;
    cin >> k;
    
    bool ok = 0;
    
    for (int i = 0; i <n ;i++){
        if (s[i] == 'Y'){
            ok = 1;
            for (int j = 0; j < n ;j++){
                cost[j][i] = 0;
            }
            dp[1<<i] = 0;
        }
        else dp[1<<i] = inf;
        cost[i][i] = inf;
    }
    
    int ans = inf;
    for (int i = 1; i < (1 << n); i++){
        int x = solve(i);
        
        int cnt = 0;
        for (int j = 0; j < n; j++){
            cnt += (i & (1 << j)) > 0;
        }
        if (cnt >= k) ans = min(ans, x);
    }
    
    if (!ok) ans = -1;
    if (k == 0) ans = 0;
    cout << ans;
}