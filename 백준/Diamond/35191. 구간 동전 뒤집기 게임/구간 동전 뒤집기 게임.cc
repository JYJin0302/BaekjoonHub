#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dp[101010][18];
map<int, ll> dp2[101010][18];


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i =0 ;i < n; i++){
        if (s[i] == 'H') dp[i][0] = 1;

        int len = 1;
        for(int j = 1; j < 18 ;j++){
            len <<= 1;
            if (i + 1 < len) break;
            if (s[i] == 'H') dp[i][j] ^= (1 << j);
            int tlen = len >> 1;
            int tj = j-1;
            while(tlen){
                dp[i][j] ^= dp[i-tlen][tj];
                tj--;
                tlen>>=1;
            }
        }

    }

    ll ans = 0;
    for(int i =0; i < n; i++){
        for(int j =0 ;j < 18;j ++){
            int len = (1 << j);
            if (i + 1 < len) break;
            
            dp2[i][j][dp[i][j]]++;

            // cout << " ij " << i << ' ' << j << " => ";
            // for(auto [a,b] : dp2[i][j]) cout << a<< ' '<< b << " | ";
            // cout << '\n';

            ans += dp2[i][j][0];

            // go Next
            for(int tj = 0; tj < j; tj++){
                int ni = i + (1 << tj);
                if (ni >= n) break;

                //cout << "GO to: " << ni << ' ' << tj << '\n';
                int val = dp[ni][tj];
                for(auto[a,b]: dp2[i][j]){
                    if (a > (1 << tj+1)) break;
                    dp2[ni][tj][a ^ val] += b;
                }
            }

        }
    }
    

    cout << ans << '\n';
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }   
    return 0;
}