
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, r, t;
    cin >>d >>r >>t;

    int tot = r +t;

    for(int i = 4; i <= 100; i++){

        int tmp = 0;
        tmp += max(0, i*(i+1)/2 - 6);
        tmp += max(0, (i-d)*(i-d+1)/ 2- 3);

        //cout <<i <<' ' <<tmp <<'\n';
        if (tmp == tot){
            cout << r - max(0, i*(i+1)/2 - 6);
            return 0;
        }
    }


}
