#include <bits/stdc++.h>
using namespace std;

int A[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            A[i][j] = 10000;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (A[i][j] == 10000){
                if (A[j][i] != 10000) A[i][j] = -A[j][i];
            }
            else A[j][i] = -A[i][j];
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        
        if (A[a][b] == 10000) cout << 0;
        else if (A[a][b] < 0) cout << 1;
        else cout << -1;
        cout << '\n';
    }
}