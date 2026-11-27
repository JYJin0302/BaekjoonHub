#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h, w;
    cin >> n >>h >> w;

    for(int i = 0; i < n; i++){

        char x, y;
        cin >> x >> y;

        if(x == 'Y' || w == 0){
            h--, w++;
            cout <<"Y ";
        }
        else {
            cout <<"N ";
        }

        if (y == 'Y' || h == 0){
            w--, h++;
            cout <<"Y\n";
        }
        else cout <<"N\n";

    }


}
