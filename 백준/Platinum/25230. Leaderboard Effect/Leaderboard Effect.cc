#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ld dp[101][1 << 17];
ld ans[101][22];

int R[20];
int C[20];
ld P[20];

const ld eps = 1e-15;

void solve(){

    int n, t;
    cin >> n >> t;

    for(int i = 0; i < n; i++){
        cin >> R[i] >> C[i] >> P[i];
    }

    dp[0][0] = 1;
    for(int i = 0; i <= t; i++){
        if (i){
            for(int j = 0; j < n; j++){
                ans[i][j] += ans[i-1][j];
            }
        }

        if (i == t) continue;

        for(int s = 0; s < (1 << n); s++){
            ld tot = 0;
            int cnt = 0;
            for(int nx = 0; nx < n; nx++){
                if (s & (1 << nx)){}
                else{
                    tot += ans[i][nx];
                    cnt++;
                }
            }
            if (cnt == 0) continue;

            for(int nx = 0; nx < n; nx++){
                if (s & (1 << nx)){}
                else{
                    ld p = 0;
                    if (tot == 0){
                        p = 1.0 / cnt;
                    }
                    else{
                        p = ans[i][nx] / tot;
                    }

                    // solve
                    int nt = i + R[nx] + C[nx];
                    if (nt <= t){
                        dp[nt][s | (1 << nx)] += dp[i][s] * p * P[nx];
                        ans[nt][nx] += dp[i][s] * p * P[nx];
                    }

                    // no solve
                    nt = i + R[nx];
                    if (nt <= t){
                        dp[nt][s | (1 << nx)] += dp[i][s] * p * (1 - P[nx]);
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(20);
    for(int i =0 ;i < n ;i++) cout << ans[t][i] << '\n';



}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}