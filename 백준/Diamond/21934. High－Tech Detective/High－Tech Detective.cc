#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

char op[10101];
int x[10101];
int cnt[10101];

ll dp[5050];
ll ndp[5050];

void solve(){
    
    int n;
    cin >> n;

    for(int i = 0; i < n*2; i++){
        cin >> op[i] >> x[i];
        cnt[x[i]]++;
    }

    vector<int> sufO(n*2+5), sufI(n*2+5);
    for(int i = n*2-1; i >= 0;i--){
        if(x[i] && cnt[x[i]] == 2) {}
        else{
            if(op[i] == 'O' && x[i] == 0) sufO[i]++;
            if(op[i] == 'I' && x[i]) sufI[i]++;
        }
        sufO[i] += sufO[i+1];
        sufI[i] += sufI[i+1];
    }

    vector<int> pS(n*2+5);
    for(int i =0 ;i < n*2; i++){
        if (x[i] && cnt[x[i]] == 2){}
        else{
            if(op[i] == 'I') pS[i]++;
            else pS[i]--;
        }
        if (i) pS[i] += pS[i-1];
    }

    dp[0] = 1;
    for(int i = 0; i < n*2;i++){
        if (x[i] && cnt[x[i]] == 2){
            continue;
        }
        
        memset(ndp, 0, sizeof ndp);
        if (op[i] == 'I'){
            if(!x[i]){
                for (int j =0; j <= n; j++){
                    (ndp[j] += dp[j]) %= mod;
                    int mult = sufO[i+1] - sufI[i+1];
                    mult -= j;
                   // cout <<"CHK: " << i << ' '<< j << ' '<< mult << endl;
                    if (mult >= 0) (ndp[j+1] += dp[j] * mult % mod) %= mod;
                }
            }
            else{
                for(int j = 0; j < n; j++){
                    (ndp[j+1] += dp[j]) %= mod;
                }
            }
        }
        else{
            if (!x[i]){
                for(int j = 1; j <= n; j++){
                    (ndp[j-1] += dp[j] * j % mod) %= mod;
                }
            }
            else{
                for(int j = 0; j <= n; j++){
                    int mult = pS[i-1] - j;
                    if (mult <= 0) break;
                    (ndp[j] += dp[j] * mult % mod) %= mod;
                }
            }
        }

        // for(int j = 0;j <= n; j++) cout << ndp[j] << ' ';
        // cout << endl;
        swap(dp, ndp);
    }

    cout << dp[0] << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}