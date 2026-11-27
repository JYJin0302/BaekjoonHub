#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n, t, s, e;
int sz;
int ntoi[1001];
int iton[1001];

vector<vector<int>> dp[20];

vector<vector<int>> mult(vector<vector<int>>& a, vector<vector<int>>& b){
    vector<vector<int>>res(sz, vector<int>(sz, inf));
    for (int i = 0; i < sz; i++){
        for (int j = 0; j < sz ; j++){
            for (int k = 0; k < sz ;k++){
                res[i][j] = min(res[i][j], a[i][k]+b[k][j]);
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> t >> s >> e;
    
    vector<int> num;
    vector<tuple<int, int, int>> inp;
    for (int i = 0; i < t; i++){
        int a, b, c;
        cin >> a>> b >> c;
        inp.push_back({a, b, c});
        
        if (ntoi[b] == 0){
            ntoi[b]++;
            num.push_back(b);
        }
        if (ntoi[c] == 0){
            ntoi[c]++;
            num.push_back(c);
        }
    }
    
    sort(num.begin(), num.end());
    
    sz = num.size();
    for (int i = 0; i < sz; i++){
        iton[i] = num[i];
        ntoi[num[i]] = i;
    }
    
    for (int i = 0; i < 20; i++){
        dp[i] = vector<vector<int>>(sz, vector<int>(sz, inf));
    }
    
    s = ntoi[s], e = ntoi[e];
    
    for (auto i :inp){
        int a,b , c;
        tie(a, b, c) = i;
        
        b = ntoi[b], c = ntoi[c];
        dp[0][b][c] = a;
        dp[0][c][b] = a;
    }
    
    for (int i = 1; i < 20; i++){
        dp[i] = mult(dp[i-1], dp[i-1]);
    }
    
    vector<vector<int>> ans = dp[0];
    n--;
    for (int i = 0; i < 20 ;i++){
        if (n % 2) ans = mult(ans, dp[i]);
        n >>= 1;
    }
    
    cout << ans[s][e];
}