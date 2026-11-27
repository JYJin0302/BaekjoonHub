
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

const ll mod = 1e9+9;

map<int, vector<ll>> tt;

vector<ll>getCnt(char a, char b, char c){

    int ix = 0;
    for(auto i : {a, b, c}){
        ix *= 28;
        if(i == '?') ix += 26;
        else if (i == char('a'-1)) ix += 27;
        else ix += int(i-'a');
    }

    if (!tt[ix].empty()) return tt[ix];

    int x, y, z;
    vector<tuple<int, int, int>> res;
    if(a == '?'){
        for(x = 0;x <26; x++){
            if(b == '?'){
                for(y = 0; y <26; y++){

                    if(c == '?'){
                        for(z = 0; z <26; z++){
                            res.push_back({x, y, z});
                        }
                    }
                    else{
                        z = c - 'a';
                        res.push_back({x, y, z});
                    }

                }
            }
            else{
                y = b - 'a';
                if(c == '?'){
                    for(z = 0; z <26; z++){
                        res.push_back({x, y, z});
                    }
                }
                else{
                    z = c - 'a';
                    res.push_back({x, y, z});
                }

            }

        }
    }
    else{

        x = a - 'a';
        if(b == '?'){
            for(y = 0; y <26; y++){

                if(c == '?'){
                    for(z = 0; z <26; z++){
                        res.push_back({x, y, z});
                    }
                }
                else{
                    z = c-'a';
                    res.push_back({x, y, z});
                }

            }
        }
        else{
            y = b - 'a';
            if(c == '?'){
                for(z = 0; z <26; z++){
                    res.push_back({x, y, z});
                }
            }
            else{
                z = c - 'a';
                res.push_back({x, y, z});
            }
        }
    }

    vector<ll>ans(9);
    for(auto f : res){
        tie(x, y, z) = f;
        if(x == y && y == z) ans[0]++;
        if(x == y && y < z) ans[1]++;
        if(x < y && y == z) ans[2]++;
        if(x < y && y < z)ans[3]++;
        if(x == y) ans[4]++;
        if(y == z) ans[5]++;
        if(x < y) ans[6]++;
        if(y < z) ans[7]++;
        ans[8]++;
    }

    tt[ix] = ans;
    return ans;

}

void solve(){

    vector<string> A(3);
    for(int i = 0; i < 3; i++) cin >>A[i];

    int n = 0;
    for(int i = 0; i < 3; i++){
        n = max(n, (int)A[i].size());
    }

    for(int i = 0; i < 3; i++){
        while(A[i].size() < n) A[i] += char('a'-1);
    }

    //cout <<A[0] <<'\n' <<A[1] <<'\n' <<A[2] <<'\n';

    vector<vector<ll>> dp(n+10, vector<ll>(4));
    // 0 : a==b==c, 1 : a==b<c, 2: a<b=c, 3: a<b<c
    // 4 : a == b, 5 : b == c, 6 : a < b, 7 : b < c, 8 : all
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){

        vector<ll> cnt = getCnt(A[0][i-1], A[1][i-1], A[2][i-1]);

        dp[i][0] = dp[i-1][0] * cnt[0] % mod;
        dp[i][1] = dp[i-1][0] * cnt[1] % mod + dp[i-1][1] * (cnt[4])%mod;
        dp[i][2] = dp[i-1][0] * cnt[2] % mod + dp[i-1][2] * (cnt[5])% mod;
        dp[i][3] = dp[i-1][0] * cnt[3] % mod + dp[i-1][1] * (cnt[6]) % mod +\
            dp[i-1][2] * (cnt[7])%mod + dp[i-1][3] * (cnt[8])%mod;

        for(int j = 0; j < 4; j++)dp[i][j] %= mod;
    }

    /*
    for(int j = 0; j < 4; j++){    for(int i = 0; i <= n; i++){
        cout << dp[i][j] <<' ';
    }
    cout <<'\n';
    }
    */
    cout<<dp[n][3] <<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--){
        solve();
    }

}

