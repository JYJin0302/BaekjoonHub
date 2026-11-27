#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

double P[20];
double dp[13][1<<13][13]; // dp[i][mask] : mask 사람들 생존, i의 차례 -> 각 사람들의 생존 확률
double tdp[13][1<<13][13];

const ld eps = 1e-15;
void solve(){
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> P[i];
        P[i] /= 100;
    }

    memset(dp, 0, sizeof dp);
    memset(tdp, 0, sizeof tdp);
    for(int b = 1; b < (1 << n); b++){


        vector<int> num;
        for(int i =0; i < n; i++){
            if(b & (1 << i)){
                num.push_back(i);
            }
        }

        if ((int)num.size() == 1){
            dp[num[0]][b][num[0]] = 1;
            continue;
        }

        // cout << "\nState: ";
        // for(auto f: num) cout <<f << ' ';
        // cout << '\n';

        int nn = (int)num.size();
        for(int j = 0; j < nn; j++){
            // find best target

            double bestChance = -1;
            vector<int> lst;

            for(int k = 0; k < nn; k++){
                if (k == j) continue;
                int nb = b ^ (1 << num[k]);
                int nxtS = (j+1)%nn;
                if (nxtS == k) nxtS = (nxtS + 1) % nn;

                if (bestChance + eps < dp[num[nxtS]][nb][num[j]]){
                    bestChance = dp[num[nxtS]][nb][num[j]];
                    lst.clear();
                    lst.push_back(k);
                }
                else if (abs(bestChance - dp[num[nxtS]][nb][num[j]]) < eps){
                    lst.push_back(k);
                }
            }

            // cout << "BEst : "<< num[j] << " => " << bestChance<< " with ";
            // for(auto f: lst) cout <<f << ' ';
            // cout << '\n';

            for(auto k: lst){
                int nb = b ^ (1 << num[k]);
                int nxtS = (j+1)%nn;
                if (nxtS == k) nxtS = (nxtS + 1) % nn;

                for(int x = 0;x < n; x++){
                    tdp[num[j]][b][x] += dp[num[nxtS]][nb][x];
                }
            }

            for(int x= 0; x < n; x++){
                tdp[num[j]][b][x] *= P[num[j]] / (int)lst.size();                
            }
        }

        // go Cycle
        for(int j = 0; j < nn; j++){
            double curP = 1;
            for(int k = 0; k < nn; k++){
                int ix = (j+k) % nn;
                for(int x = 0;x < n; x++){
                    dp[num[j]][b][x] += tdp[num[ix]][b][x] * curP;
                }
                curP *= 1 - P[num[ix]];
            }

            for(int x = 0; x < n; x++){
                dp[num[j]][b][x] /= 1 - curP;
            }
        }

        // cout <<" result: \n";
        // for(auto f: num){
        //     cout << f << " => ";
        //     for(int x= 0;x  < n;x ++){
                
        //         cout << dp[f][b][x] << ' ';
        //     }
        //     cout << '\n';
        // }

    }

    cout << fixed << setprecision(2);
    for(int x =0 ;x < n; x++){
        cout << dp[0][(1 << n)-1][x] * 100 << ' ';
    }
    cout << '\n';

    
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