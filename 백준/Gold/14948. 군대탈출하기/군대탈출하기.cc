#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[101][101];
bool dp[101][101][2];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i= 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    
    int ans = 1e9;
    int l = max(A[0][0], A[n-1][m-1]), r = 1e9;
    while(l <= r){
        
        int mid = (l+r)/2;
        
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        while(!q.empty()){
            
            int a, b, c;
            tie(a, b, c) = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++){
                int na = a + dx[i];
                int nb = b + dy[i];
                
                if (inGrid(na, nb)){
                    
                    if (A[na][nb] > mid){
                        int nna = na + dx[i];
                        int nnb = nb + dy[i];
                        if (inGrid(nna, nnb) && c == 0 && A[nna][nnb] <= mid && !dp[nna][nnb][1]){
                            dp[nna][nnb][1] = 1;
                            q.push({nna, nnb, 1});
                        }
                    }
                    else if (!dp[na][nb][c]){
                        dp[na][nb][c] = 1;
                        q.push({na, nb, c});
                    }
                }
            }
        }
        
        if (dp[n-1][m-1][0] || dp[n-1][m-1][1]){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
        
    }
    
    cout << ans;
}