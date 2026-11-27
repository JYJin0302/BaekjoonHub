#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 10;

int C[100][100];

int dp[30][100][100];
int tmp[100][100];
int tmp2[100][100];

int n;
void addM(int A[][100], int B[][100], int C[][100]){
    for(int i =0; i < n;i++){
        for(int j = 0; j < n; j++){
            for(int k =0;k < n; k++){
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
}


void solve(){
    
    int m;

    cin >>n >> m;

    for(int i =0 ; i < n; i++){
        for(int j =0; j < n; j++){
            cin>> C[i][j];
        }
    }

    for(int i =0 ; i< n; i++){
        for(int j =0 ; j < n; j++){
            dp[0][i][j] = C[i][j];
        }
    }

    for(int j = 1; j < 30; j++){
        for(int a = 0;a < n; a++){
            for(int b=0;b < n; b++){
                dp[j][a][b] = INF;
            }
        }
        addM(dp[j-1], dp[j-1], dp[j]);
    }

    // for(int t=0; t < 3; t++){
    //     cout << "DP : "<< t<< '\n';
    //     for(int i = 0; i < n; i++){
    //         for(int j =0 ; j < n; j++){
    //             cout << dp[t][i][j] << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }

    for(int a= 0;a < n; a++){
        for(int b = 0; b < n; b++){
            tmp[a][b] = INF;
        }
    }
    tmp[0][0] = 0;

    int ans = 0;
    for(int i = 29; i >= 0; i--){
        for(int a= 0; a < n;a ++){
            for(int b = 0; b < n; b++){
                tmp2[a][b] = INF;
            }
        }

        addM(tmp, dp[i], tmp2);

        bool found = 0;
        for(int j = 0; j < n; j++){
            if (tmp2[0][j] <= m) found = 1;
        }
        if(found){
            ans += 1 << i;
            swap(tmp, tmp2);
            // cout << "found: " << i << '\n';
            // for(int a=0 ;a <n ;a++){
            //     for(int b =0 ;b  < n; b++){
            //         cout << tmp[a][b] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
        }
    }
    cout << ans << '\n';



}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
