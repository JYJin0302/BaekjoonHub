#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    int tot = 0;
    for(auto f : A) tot += f;

    vector<bitset<50100>> dp;
    bitset<50100> bs;
    bs[0] = 1;

    dp.push_back(bs);
    for(int i = 0; i < n; i++){
        bs |= bs << A[i];
        dp.push_back(bs);
    }

    // cout << "DP: \n";
    // for(auto f : dp){
    //     for(int j =0 ;j <= tot; j++){
    //         cout << f[j];
    //     }
    //     cout << '\n';
    // }
    // cout << endl;

    int res = (tot + 1) / 2;
    while(!dp[n][res]) res++;

    int ansVal = 2 * res - tot;
    vector<int> B(n);
    for(int i = n-1; i >= 0; i--){
        if (res >= A[i] && dp[i][res-A[i]]) B[i] = A[i], res -= A[i];
        else B[i] = -A[i];
    }
    
    vector<int> ans;
    while(B.size() >= 2){
        int sn = B.size();
        for(int j = 0 ; j < sn-1; j++){
            if (B[j] * B[j+1] <= 0){
                ans.push_back(j+1);
                int nval = B[j] + B[j+1];
                
                vector<int> tmp;
                for(int f = 0; f  < j; f++) tmp.push_back(B[f]);
                if (nval != 0) tmp.push_back(nval);
                for(int f = j+2; f < sn; f++) tmp.push_back(B[f]);
                B = tmp;
                break;
            }
        }
        //for(auto [a,b] : B) cout << "(" << a << ' '<< b << ") ";
        //cout << endl;
        sn--;
    }

    cout << ansVal << ' ' << ans.size() << '\n';
    for(auto f : ans) cout << f<< ' ';
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int t = 1;
    cin >> t;
    while (t--) solve();
}
