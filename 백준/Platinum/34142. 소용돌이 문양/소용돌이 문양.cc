#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int of = 10;
int C[2030][2030];
int dpU[2030][2030];
int dpR[2030][2030];
int dpD[2030][2030];
int dpL[2030][2030];
int dpX[2030][2030];

void solve() {
    
    int n, m, k;
    cin >> n >> m >> k;

    ll p, q;
    cin >> p >> q;
    
    while(k--){
        int a, b, c;
        cin >> a >> b >> c;
        a += of, b += of;

        C[a][b]++;

        // U
        dpU[a-2][b-2]++; dpU[a-2][b+2]--;
        dpU[a-c-2][b-c-2]--; dpU[a-c-4][b-c]++;
        dpU[a-c-2][b+c+2]++; dpU[a-c-4][b+c]--;

        // R
        dpR[a-2][b+2]++; dpR[a+2][b+2]--;
        dpR[a-c-2][b+c+2]--; dpR[a-c][b+c+4]++;
        dpR[a+c+2][b+c+2]++; dpR[a+c][b+c+4]--;

        // D
        dpD[a+2][b+2]++; dpD[a+2][b-2]--;
        dpD[a+c+2][b+c+2]--; dpD[a+c+4][b+c]++;
        dpD[a+c+2][b-c-2]++; dpD[a+c+4][b-c]--;
        
        // L
        dpL[a+2][b-2]++; dpL[a-2][b-2]--;
        dpL[a+c+2][b-c-2]--; dpL[a+c][b-c-4]++;
        dpL[a-c-2][b-c-2]++; dpL[a-c][b-c-4]--;

        dpX[a+c-1][b+c]--;
        dpX[a-1][b]++;
    }


    // process U
    for(int i = 2020; i >= 5; i--){
        for(int j = 5; j <= 2020; j++){
            dpU[i][j] += dpU[i+2][j-2];
        }
    }
     for(int i = 2020; i >= 5; i--){
        for(int j = 5; j <= 2020; j++){
            dpU[i][j] += dpU[i+2][j+2];
        }
    }

     for(int i = 2020; i >= 5; i--){
        for(int j = 5; j <= 2020; j++){
            dpU[i][j] +=  dpU[i][j-1];
        }
    }

    // cout << "DPU: \n";
    // for(int i =1;i <= n; i++){
    //     for(int j = 1;j <= m; j++){
    //         cout << dpU[i +of][j+of] << ' ';
    //     }
    //     cout << '\n';
    // }
    // process R

    for(int j = 5; j <= 2020; j++){
        for(int i = 5; i <= 2020; i++){
            dpR[i][j] += dpR[i+2][j-2];
        }
    }
    for(int j = 5; j <= 2020; j++){
        for(int i = 5; i <= 2020; i++){
            dpR[i][j] += dpR[i-2][j-2];
        }
    }
    for(int j = 5; j <= 2020; j++){
        for(int i = 5; i <= 2020; i++){
            dpR[i][j] += dpR[i-1][j];
        }
    }
    // cout << "DP R\n";
    // for(int i =1;i <= n; i++){
    //     for(int j = 1;j <= m; j++){
    //         cout << dpR[i +of][j+of] << ' ';
    //     }
    //     cout << '\n';
    // }
    // process D
    for(int i = 5; i <= 2020; i++){
        for(int j = 2020; j >= 5; j--){
            dpD[i][j] += dpD[i-2][j-2];
        }
    }
    for(int i = 5; i <= 2020; i++){
        for(int j = 2020; j >= 5; j--){
            dpD[i][j] += dpD[i-2][j+2];
        }
    }
    for(int i = 5; i <= 2020; i++){
        for(int j = 2020; j >= 5; j--){
            dpD[i][j] += dpD[i][j+1];
        }
    }
    
    // cout << "Dp D\n";
    // for(int i =1;i <= n; i++){
    //     for(int j = 1;j <= m; j++){
    //         cout << dpD[i +of][j+of] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // process L
    for(int j = 2020; j >= 5; j--){
        for(int i = 2020; i >= 5; i--){
            dpL[i][j] += dpL[i-2][j+2];
        }
    }
    for(int j = 2020; j >= 5; j--){
        for(int i = 2020; i >= 5; i--){
            dpL[i][j] += dpL[i+2][j+2];
        }
    }
    for(int j = 2020; j >= 5; j--){
        for(int i = 2020; i >= 5; i--){
            dpL[i][j] += dpL[i+1][j];
        }
    }
    // cout << "DP L\n";
    // for(int i =1;i <= n; i++){
    //     for(int j = 1;j <= m; j++){
    //         cout << dpL[i +of][j+of] << ' ';
    //     }
    //     cout << '\n';
    // }

    // process X

    for(int i = 2020; i >= 5; i--){
        for(int j = 2020; j >= 5; j--){
            dpX[i][j] -= dpX[i+1][j+1];
        }
    }

    // cout << "DPX\n";
    // for(int i =1;i <= n; i++){
    //     for(int j = 1;j <= m; j++){
    //         cout << dpX[i +of][j+of] << ' ';
    //     }
    //     cout << '\n';
    // }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
            int io = i + of;
            int jo = j + of;
            ll cnt = dpU[io][jo] + dpR[io][jo] + dpD[io][jo] + dpL[io][jo] + dpX[io][jo] + C[io][jo];
            
            ll res = 0;
            res = 1ll * i * p;
            res ^= 1ll * j * q;
            res ^= cnt;
            ans += res;
        }
    }
    cout << ans << '\n';
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