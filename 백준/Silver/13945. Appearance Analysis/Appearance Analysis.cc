
#include <bits/stdc++.h>
using namespace std;

    int ans = 0;
map<string, bool> mp;
int n, m, tn, tm1;
string A[133];

void solve(int x, int y){

    string s1;
    for(int i = 0; i < tn; i++){
        for(int j = 0; j < tm1; j++){
            s1 += A[x+i][y+j];
        }
    }

    if (mp[s1]){
        return;
    }
    ans++;
    mp[s1] = 1;

    string s2;
    for(int i = 0; i < tn; i++){
        for(int j = 0; j < tm1; j++){
            s2 += A[x + tn - 1 - i][y + tm1 - 1 - j];
        }
    }
    mp[s2] = 1;

    if(tn == tm1){
        string t3;
        for(int j= 0; j <tm1; j++){
            for(int i = tn-1; i >= 0; i--){
                t3 += A[x+i][y+j];
            }
        }
        mp[t3] = 1;

        string t4;
        for(int j= tm1-1; j >= 0; j--){
            for(int i = 0; i <tn; i++){
                t4 += A[x+i][y+j];
            }
        }
        mp[t4] = 1;

        //cout << s1 <<' ' <<s2 <<' ' <<t3 <<' ' <<t4 <<'\n';
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >>n >>m;

    for(int i = 0; i < n; i++) cin >>A[i];

    //cout <<"?";
    int x =1, y =1;

    tn= 0, tm1= 0;
    for(int i = 1; i < m; i++){
        if (A[1][i] != '#') tm1++;
        else break;
    }

    for(int i = 1; i < n;i++){
        if (A[i][1]!= '#')tn++;
        else break;
    }



    for(int i = 1; i < n; i += tn+1){
        for(int j = 1; j <m; j+= tm1+1){
            solve(i, j);
        }
    }
    cout <<ans;
}
