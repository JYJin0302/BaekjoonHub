#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

char YZ[101][101];
char XZ[101][101];
char XY[101][101];
bool chk[101][101];

void solve(){
    int n;
    cin >> n;

    for(int z = n-1; z >= 0; z--){
        for(int y = 0; y < n; y++){
            cin >> YZ[y][z];
        }
    }

    for(int x = n-1; x >= 0; x--){
        for(int z = 0; z < n; z++){
            cin >> XZ[x][z];
        }
    }

    for(int y = n-1; y >= 0; y--){
        for(int x = 0; x < n; x++){
            cin >> XY[x][y];
        }
    }

    for(int z = n-1; z >=0 ; z--){

        vector<int> xL, yL;
        for(int i =0 ;i < n; i++){
            if (XZ[i][z] == '1') xL.push_back(i);
            if (YZ[i][z] == '1') yL.push_back(i);
        }

        int cnt = 0;
        int s1 = (int)xL.size();
        int s2 = (int)yL.size();

        if (s1 == 0 && s2 == 0){} // ok
        else if(s1 == 0 || s2 == 0){
            cout << "No\n";
            return;
        }
        else{
            for(auto x : xL) {
                cnt = 0;
                for(auto y : yL){
                    if(XY[x][y] == '1'){
                        cnt++;
                        chk[x][y] = 1;
                    }
                }
                if(cnt == 0){
                    cout << "No\n";
                    return;
                }
            }

            for(auto y : yL) {
                cnt = 0;
                for(auto x : xL){
                    if(XY[x][y] == '1'){
                        cnt++;
                        chk[x][y] = 1;
                    }
                }
                if(cnt == 0){
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    
    for(int x = 0; x < n; x++){
        for(int y= 0 ; y < n; y++){
            if (XY[x][y] == '1' && !chk[x][y]){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}