#include <bits/stdc++.h>
using namespace std;

int n, m, k, w, h; 
bool A[41][41];

void insert(vector<vector<bool>>& v, int pos = 0){
    
    if (pos == 4) return;
    
    if (pos == 0){
        
        int pi = -1, pj = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <m; j++){
                bool ok = 1;
                
                for (int x = 0; x < w; x++){
                    for(int y = 0; y < h; y++){
                        if (i+x >= n || j+y >= m || (v[x][y] && A[i+x][j+y])) ok = 0;
                    }
                }
                
                if (ok){
                    for (int x = 0; x < w; x++){
                        for(int y = 0; y < h; y++){
                            A[i+x][j+y] |= v[x][y];
                        }
                    }
                    
                    return;
                }
            }
        }
    }
    else if (pos == 1){
        
        int pi = -1, pj = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <m; j++){
                bool ok = 1;
                
                for (int x = 0; x < w; x++){
                    for(int y = 0; y < h; y++){
                        if (i+y >= n || j+w-1-x >= m || (v[x][y] && A[i+y][j+w-1-x])) ok = 0;
                    }
                }
                
                if (ok){
                    for (int x = 0; x < w; x++){
                        for(int y = 0; y < h; y++){
                            A[i+y][j+w-1-x] |= v[x][y];
                        }
                    }
                    
                    return;
                }
            }
        }
    }
    else if (pos == 2){
        
        int pi = -1, pj = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <m; j++){
                bool ok = 1;
                
                for (int x = 0; x < w; x++){
                    for(int y = 0; y < h; y++){
                        if (i+w-1-x >= n || j+h-1-y >= m || (v[x][y] && A[i+w-1-x][j+h-1-y])) ok = 0;
                    }
                }
                
                if (ok){
                    for (int x = 0; x < w; x++){
                        for(int y = 0; y < h; y++){
                            A[i+w-1-x][j+h-1-y] |= v[x][y];
                        }
                    }
                    
                    return;
                }
            }
        }
    }
    else if (pos == 3){
        
        int pi = -1, pj = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <m; j++){
                bool ok = 1;
                
                for (int x = 0; x < w; x++){
                    for(int y = 0; y < h; y++){
                        if (i+h-1-y >= n || j+x >= m || (v[x][y] && A[i+h-1-y][j+x])) ok = 0;
                    }
                }
                
                if (ok){
                    for (int x = 0; x < w; x++){
                        for(int y = 0; y < h; y++){
                            A[i+h-1-y][j+x] |= v[x][y];
                        }
                    }
                    
                    return;
                }
            }
        }
    }
    insert(v, pos+1);
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    while(k--){
        
        
        cin >> w >> h;
        
        vector<vector<bool>> inp(w, vector<bool>(h));
        for (int i = 0; i < w; i++){
            for (int j = 0; j < h; j++){
                int tmp ;
                cin >> tmp;
                inp[i][j] = tmp;
            }
        }
        
        insert(inp);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans += A[i][j];
            
        }
    }
    cout << ans;
}