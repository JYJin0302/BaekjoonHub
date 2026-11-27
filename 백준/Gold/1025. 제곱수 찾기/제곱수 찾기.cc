// 등차수열의 등비 : 음수, 0, 양수 모두 가능!

#include <bits/stdc++.h>
using namespace std;

int n, m, ans = -1;
vector<string> grid;

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int getNum(string s){
    int x = stoi(s);
    int rx = (int)sqrt(x);
    
    if (x == rx*rx) return x;
    return -1;
}

void solve(int x){
    // x : 수의 길이
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // 시작점: {i, j}
            
            for (int dx = -8; dx <= 8; dx++){
                for (int dy = -8; dy <= 8; dy++){
                    
                    // 등비 : {dx, dy}
                    
                    int ti = i, tj = j;
                    string c = "";
                    
                    while(inGrid(ti, tj) && c.size() < x){
                        c += grid[ti][tj];
                        ti += dx;
                        tj += dy;
                    }
                    
                    if (c.size() == x){
                        ans = max(ans, getNum(c));
                    }
                }
            }            
        }
    }    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    grid = vector<string>(n);
    for(auto& i : grid) cin >> i;
    
    for (int i = 1; i <= max(n, m); i++) solve(i);
    
    cout << ans;
}