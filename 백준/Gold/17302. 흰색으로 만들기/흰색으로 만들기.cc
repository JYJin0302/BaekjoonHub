#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x >=0  && x < n && y >= 0&& y < m;
}

int main(){
    
    
    cin >> n >> m;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (inGrid(ni, nj)){
                    A[ni][nj] = char('W' + 'B' - A[ni][nj]);
                }
            }
            
        }
    }
    
    cout << "1\n";
    for (int i = 0; i < n; i++){
        for (int j= 0; j < m; j++){
            if (A[i][j] == 'W') cout << 2;
            else cout << 3;
        }
        cout << '\n';
    }
    
}