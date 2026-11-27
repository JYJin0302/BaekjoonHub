
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Data{
    ll x1, t1, x2, t2;

    bool operator<(Data& o){
        return x1 <o.x1;
    }
};

ll INF = 1E15;
ll dp[505][505], tmp[505][505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s1, s2;
    cin >>n >>s1 >>s2;

    vector<Data> A(n);
    for(auto&i :A){
        cin >>i.x1 >>i.t1 >>i.x2 >>i.t2;
    }
    sort(A.begin(), A.end());

    for(int i = 0; i <= s1; i++){
        for(int j = 0; j <= s2; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){

        for(int j = 0; j <= s1; j++){
            for(int k = 0; k <= s2; k++){
                tmp[j][k] = dp[j][k];
            }
        }

        for(int j = 0; j <= s1; j++){
            for(int k = 0; k <= s2; k++){

                // try 1st
                if(j < s1){
                    int nj = j + A[i].x1;
                    int nk = k;

                    if (nj >= s1){
                        nk += nj-s1;
                        nj = s1;
                        nk = min(s2, nk);
                    }

                    tmp[nj][nk] = min({tmp[nj][nk], dp[j][k] + A[i].t1});
                }

                // try 2nd
                int nj = j;
                int nk = k + A[i].x2;
                nk = min(s2, nk);

                tmp[nj][nk] = min({tmp[nj][nk], dp[j][k] + A[i].t2});

            }
        }

        for(int j = 0; j <= s1; j++){
            for(int k = 0; k <= s2; k++){
                dp[j][k] = min(dp[j][k], tmp[j][k]);
            }
        }
        
    }

    if(dp[s1][s2] == INF) dp[s1][s2] = -1;
    cout <<dp[s1][s2];

}
