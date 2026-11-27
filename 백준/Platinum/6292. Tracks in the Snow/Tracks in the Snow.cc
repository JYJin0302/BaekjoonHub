#include <bits/stdc++.h>
using namespace std;

int h, w;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x >= 0 && x < h && y >= 0 && y < w;
}

vector<string> A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> h >> w;
    
    A = vector<string> (h);
    for(auto& i : A) cin >> i;
    
    if (A[0][0] == '.'){
        cout << 0;
        return 0;
    }
    
    int v[4001][4001];
    for (int i = 0; i < h; i++) for(int j = 0; j < w; j++) v[i][j] = -1;
    
    int ans = 1;
    deque<tuple<int, int, int>> q;
    q.push_front({0, 0, 1});
    while(!q.empty()){
        
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop_front();
        
        if (v[a][b] != -1) continue;
        v[a][b] = c;
        
        ans = max(ans, c);
        
        for(int i =0 ;i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && v[na][nb] == -1 && A[na][nb] != '.'){
                if (A[na][nb] != A[a][b]){
                    q.push_back({na, nb, c+1});
                }
                else q.push_front({na, nb, c});
            }
        }
    }
    
    cout << ans;
}