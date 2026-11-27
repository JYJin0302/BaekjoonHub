#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, s, e, t;
const ll mod = 1e6+3;

vector<vector<ll>> dp[30];

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b) {

    vector<vector<ll>> res(n*5, vector<ll>(n*5));
    for (int k = 0; k < n*5; k++) {
        for (int i = 0; i < n*5; i++) {
            ll temp = 0;
            for (int j = 0; j < n*5; j++) {
                temp += a[k][j] * b[j][i];
                temp %= mod;
            }
            res[k][i] = temp;
        }
    }

    return res;
}

void init(){
    for(int i = 0; i < 30; i++){
        dp[i] = vector<vector<ll>> (n*5, vector<ll>(n*5));
    }
    
    for (int i = 0; i < n; i++){
        
        int ti = i*5;
        
        dp[0][ti+4][ti+3] = 1;
        dp[0][ti+3][ti+2] = 1;
        dp[0][ti+2][ti+1] = 1;
        dp[0][ti+1][ti] = 1;
    }
}

void setDP(){
    for (int i = 1; i < 30; i++){
        dp[i] = mult(dp[i-1], dp[i-1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> s >> e >> t;
    s--, e--;
    
    init();
    
    
    for(int i = 0; i < n; i++){
        string st;
        cin >> st;
        
        int ni = i*5;
        
        for (int j = 0; j < n; j++){
            if (st[j] == '0') continue;
            int v= st[j] - '1';
            
            int nj = j*5;
            
            dp[0][ni][nj+v] = 1;
        }
    }
    
    setDP();
    
    vector<vector<ll>> ans = dp[0];
    t--;
    
    int ix = 0;
    while(t){
        if (t % 2) ans = mult(ans, dp[ix]);
        ix++;
        t /= 2;
    }
    
    cout << ans[s*5][e*5];
}