#include <bits/stdc++.h>
using namespace std;

int A[301][301];

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int l;
bool inGrid(int x, int y){
    return x >= 0 && x < l && y >= 0 && y < l;
}
int main(){
    
    int t;
    cin >> t;
    while(t--){

        
        cin >> l;
        
        for(int i = 0; i <= l; i++){
            for (int j = 0; j <= l; j++){
                A[i][j] = 10000000;
            }
        }
        
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        A[x1][y1] = 0;
        queue<pair<int, int>> q;
        q.push({x1, y1});
        while(!q.empty()){
            
            int a, b;
            tie(a,b) = q.front();
            q.pop();
            
            for (int i = 0; i < 8; i++){
                
                int na = a + dx[i];
                int nb = b + dy[i];
                
                if (inGrid(na, nb) && A[na][nb] == 10000000){
                    A[na][nb] = A[a][b] + 1;
                    q.push({na, nb});
                }
            }            
        }
        
        cout << A[x2][y2] << '\n';
            
    }
    
}