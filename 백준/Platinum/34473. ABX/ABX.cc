#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e15;
ll dp[6060][3030];
char from[6060][3030];


void solve(){

    int n;
    cin >> n;
    
    string s;
    cin >> s;

    s = '.' + s;

    // getMax
    for(int i = 0; i <= 2*n + 10; i++){
        for(int j = 0; j <= n + 10 ;j++){
            dp[i][j] = -INF;
        }
    }
    

    // vector<ll> Apos(n+1), Bpos(n+1);
    // for(int i = n; i >= 1; i--){
    //     if (s[i] == 'A') Apos[i] += i;
    //     else if (s[i] == 'B') Bpos[i] += i;
    //     Apos[i] += Apos[i+1];
    //     Bpos[i] += Bpos[i+1];
    // }


    dp[0][0] = 0;
    for(int i = 1; i <= 2*n; i++){
        for(int j = 0; j <= min(i, n); j++){
            if (s[i] != 'B'){
                if(j == 0) dp[i][j] = -INF;
                else{
                    ll cost = (j-1) * i - (n - j) * i;
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + cost);
                    if(dp[i][j] == dp[i-1][j-1] + cost) from[i][j] = 'A';
                }
            }
            if (s[i] != 'A'){
                ll cnt = i - j;
                if (cnt){
                    ll cost = (cnt - 1) * i - (n - cnt) * i;
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + cost);
                    if(dp[i][j] == dp[i-1][j] + cost) from[i][j] = 'B';
                }
            }
        }
    }


    int a= n*2, b = n;
    string ans2;
    while(a >= 1){
        ans2 += from[a][b];
        if(from[a][b] == 'A') b--;
        a--;
    }

    reverse(all(ans2));

    for(int i = 0; i <= 2*n + 10; i++){
        for(int j = 0; j <= n + 10 ;j++){
            dp[i][j] = INF;
        }
    }
    
    dp[0][0] = 0;
    for(int i = 1; i <= 2*n; i++){
        for(int j = 0; j <= min(i, n); j++){
            if (s[i] != 'B'){
                if(j == 0) dp[i][j] = INF;
                else{
                    ll cost = (j-1) * i - (n - j) * i;
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost);
                    if(dp[i][j] == dp[i-1][j-1] + cost) from[i][j] = 'A';
                }
            }
            if (s[i] != 'A'){
                ll cnt = i - j;
                if (cnt){
                    ll cost = (cnt - 1) * i - (n - cnt) * i;
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + cost);
                    if(dp[i][j] == dp[i-1][j] + cost) from[i][j] = 'B';
                }
            }
        }
    }

    a = n*2, b= n;
    string ans1;
    while(a >= 1){
        ans1 += from[a][b];
        if(from[a][b] == 'A') b--;
        a--;
    }
    reverse(all(ans1));

    cout << ans1 << '\n' << ans2 << '\n';

}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}