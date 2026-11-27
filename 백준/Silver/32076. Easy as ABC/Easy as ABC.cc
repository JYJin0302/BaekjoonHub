#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char G[3][3];
set<string> ans;

int dx [] = {-1, -1, -1,0 ,1 ,1, 1, 0};
int dy[] = {-1, 0,1 ,1, 1, 0, -1, -1};

string track = "???";
int tx, ty;
void choose(int x, int y, int cnt = 0){

    if(cnt == 3){
        ans.insert(track);
        return;
    }
    if(cnt == 2 && x == tx && y== ty) return;
    track[cnt] = G[x][y];
    if(cnt == 0) tx = x, ty = y;

    for(int i =0 ;i < 8; i++){
        int nx = x  +dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
            choose(nx, ny, cnt+1);
        }
    }
}

void solve(){

    for(int i =0 ; i< 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> G[i][j];
        }
    }

    for(int i =0 ; i< 3; i++){
        for(int j =0 ; j < 3; j++){
            choose(i, j, 0);
        }
    }

    cout << *ans.begin();
    

}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}