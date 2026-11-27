#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


bool dp[1010][1010][2];

void solve(){
    
    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for(int i =0 ;i < n; i++){
        int a, b;
        cin >> a>>b;
        A[i] = mp(a, b);
    }

    for(int i = 1; i <= 1000; i++){
        dp[0][i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        auto[l, r] = A[i-1];

        for(int j = 1; j <= 1000; j++){
            if (dp[i-1][j][0] || dp[i-1][j-1][0] || dp[i-1][j+1][0]){
                if (j >= l && j <= r) dp[i][j][0] = 1;
                else dp[i][j][1] = 1;
            }
            else if (dp[i-1][j][1] || dp[i-1][j-1][1] || dp[i-1][j+1][1]){
                if(j >= l && j <= r) dp[i][j][1] = 1;
            }
        }
    }

    for(int i = 1; i <= 1000; i++){
        if (dp[n][i][0] || dp[n][i][1]){
            cout << "World Champion\n";
            return;
        }
    }
    cout << "Surrender\n";



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