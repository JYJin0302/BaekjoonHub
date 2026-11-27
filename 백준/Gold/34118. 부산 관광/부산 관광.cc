#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


int n;
string s1, s2;
int dp[2020][2020];
int cost[4];

int getDp(int a, int b){
    if (a + b == 0) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    int res = 1e9 + 10;
    if (a && s1[a] == '0') res = min(res, getDp(a-1, b));
    if (b && s2[b] == '0') res = min(res, getDp(a, b-1));
    if (a >= 1) res = min(res, getDp(a-1, b) + cost[0]);    
    if (b >= 1) res = min(res, getDp(a, b-1) + cost[0]);
    
    if (a >= 3) res = min(res, getDp(a-3, b) + cost[1]);    
    if (b >= 3) res = min(res, getDp(a, b-3) + cost[1]);
    
    if (a >= 5) res = min(res, getDp(a-5, b) + cost[2]);    
    if (b >= 5) res = min(res, getDp(a, b-5) + cost[2]);
    
    if (a == b && a >= 4 && b >= 4) res = min(res, getDp(a-4, b-4) + cost[3]);    
    return dp[a][b] = res;
}

void solve() {
    
    cin >> n;
    cin >> s1 >> s2;

    n += 10;
    for(int i =0 ; i < 10 ;i++){
        s1 += '0';
        s2 += '0';
    }
    s1 = 'x' + s1;
    s2 = 'x' + s2;

    for(int i = 0; i <4 ; i++) cin >> cost[i];

    memset(dp, -1, sizeof dp);
    cout << getDp(n, n) << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}