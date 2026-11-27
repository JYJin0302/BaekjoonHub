#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

const int mod = 998244353;
ll dp[10101];
ll tmp[10101];

void solve(){

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> A(n);
    for(auto& i : A) cin>> i;

    vector<pair<int, int>> B;
    for(int i = 0 ;i < n; i+= n/m){
        B.push_back(mp(A[i], A[i + n/m - 1]));
    }

    int tn = (int)B.size();
    for(int i = 1; i <= B[1].x - 1; i++){
        dp[i] = 1 + dp[i-1];
    }

    for(int i = 1; i < tn; i++){
        int L = B[i-1].y + 1;
        int R;
        if (i == tn-1) R = k;
        else R = B[i+1].x - 1;
        for(int j = L; j <= R; j++) tmp[j] = 0;

        int md = B[i].x;

        int lLim = 0;
        if (i == 1) lLim = 1;
        else lLim = B[i-2].y + 1;
        // 1 : L ~ md - 1
        for(int j = L; j < md;  j++){
            int tL = 2 * B[i-1].y - j;
            tL = max(tL, lLim);
            int tR = j-1;
            tmp[j] = (dp[tR] - dp[tL-1] + mod) % mod;
        }

        // md ~ R
        for(int j = md ;j <= R; j++){
            int tL = 2 * B[i-1].y - j;
            tL = max(tL, lLim);
            int tR = 2 * B[i].x - j - 1;
            if(tL <= tR) tmp[j] = (dp[tR] - dp[tL-1] + mod) % mod;
        }

        dp[L-1] = 0;
        for(int j = L; j <= R; j++){
            dp[j] = tmp[j] + dp[j-1];
            dp[j] %= mod;
        }
    }

    cout << dp[k] << '\n';

    
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