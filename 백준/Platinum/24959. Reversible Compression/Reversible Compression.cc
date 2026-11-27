#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
int dp[555][555];
string s;
int getDp(int l, int r){
    if (dp[l][r] != -1)return dp[l][r];
    if (l == n+1 && r == 0) return dp[l][r] = 0;

    int res = 1e9;
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){

            if (a == 0 && b == 0){
                if (l != n+1 && r != 0 && s[l] == '0' && s[r] == '0'){
                    res = min(res, getDp(l+1, r-1) + 1);
                }
            }
            else if (a == 0){
                if(l != n+1 && s[l] == char('0' + b)){
                    res = min(res, getDp(l+1, r) + 1);
                }
            }
            else if (b == 0){
                if (r != 0 && s[r] == char('0' + a)){
                    res = min(res, getDp(l, r-1) + 1);
                }
            }
            else{

                // check
                bool ok = 1;
                if (l > a && l + b - 1 <= n){
                    for(int j = 0; j < b ;j++){
                        if(s[l+j] != s[l+j-a]) ok = 0;
                    }
                }
                else ok = 0;

                if (r >= a + b){
                    for(int j =0; j < a; j++){
                        if (s[r-j] != s[r-j-b]) ok = 0;
                    }
                }
                else ok = 0;

                if (ok){
                    res = min(res, getDp(l+b, r - a) + 1);
                }
            }
        }
    }

    return dp[l][r] = res;
}

string ans;

void getAns(int l, int r){
    if (l == n+1 && r == 0) return;

    int res = getDp(l, r);
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){

            if (a == 0 && b == 0){
                if (l != n+1 && r != 0 && s[l] == '0' && s[r] == '0'){
                    if (getDp(l+1, r-1) + 1 == res){
                        ans += char('0' + a);
                        ans += char('0' + b);
                        getAns(l+1, r-1);
                        return;
                    }
                }
            }
            else if (a == 0){
                if(l != n+1 && s[l] == char('0' + b)){
                    if (res == getDp(l+1, r) + 1){
                        ans += char('0' + a);
                        ans += char('0' + b);
                        getAns(l+1, r);
                        return;
                    }
                }
            }
            else if (b == 0){
                if (r != 0 && s[r] == char('0' + a)){
                    if (res == getDp(l, r-1) + 1){
                        ans += char('0' + a);
                        ans += char('0' + b);
                        getAns(l, r-1);
                        return;
                    }
                }
            }
            else{

                // check
                bool ok = 1;
                if (l > a && l + b - 1 <= n){
                    for(int j = 0; j < b ;j++){
                        if(s[l+j] != s[l+j-a]) ok = 0;
                    }
                }
                else ok = 0;

                if (r >= a + b){
                    for(int j =0; j < a; j++){
                        if (s[r-j] != s[r-j-b]) ok = 0;
                    }
                }
                else ok = 0;

                if (ok){
                    if(res == getDp(l+b, r - a) + 1){
                        ans += char('0' + a);
                        ans += char('0' + b);
                        getAns(l+b, r-a);
                        return;
                    }
                }
            }
        }
    }

}


void solve(){
    
    cin >> s;

    memset(dp, -1, sizeof dp);
    n = (int)s.size();
    s = '.' + s; // 1-idx

    int len = getDp(1, n);
    
    getAns(1, n);
    cout << ans << '\n';


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