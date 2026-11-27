#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, d, c;
long double dp[13][13][13];

long double cmb(int a, int b){
    long double res = 1;
    if (a < b) return 0;

    for(int i = 0; i <b; i++){
        res *= a-i;
    }
    for(int i = 1; i <= b; i++) res /= i;
    return res;
}

long double solve(int a, int b, int c){
    if(dp[a][b][c] != -1) return dp[a][b][c];
    if(dp[b][a][c] != -1) return dp[a][b][c] = dp[b][a][c];

    long double tot = 0;
    for(int j = 0; j <= min(a, d); j++){
        for(int k = 0; k <= min(b, d); k++){
            for(int w = 0; w <= min(c, d); w++){

                if(j+k+w >d || j + k + w == 0)continue;

                tot += (1 + solve(a-j, b-k, c-w)) *cmb(n-a-b-c, d-j-k-w) * cmb(a, j) *cmb(b, k) * cmb(c, w);
            }
        }
    }

    long double t1 = cmb(n, d);
    long double t2 = cmb(n-a-b-c, d);

    tot += t2;

    //cout <<"Curr:"<< a <<' ' <<b <<'\n';
    //cout << tot << ' ' <<t1<< ' ' <<t2 <<'\n';
    return dp[a][b][c] = tot / (t1-t2);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i =0;i <= 10; i++){
        for(int j = 0; j <=10; j++){
            for(int w = 0; w<= 10; w++){

                dp[i][j][w] = -1;
                if(i+w == 0 || j+w == 0) dp[i][j][w] = 0;
            }
        }
    }


    cin >>n >> d >>c;

    vector<int> A(c), B(c);
    for(auto& i :A) cin >>i;
    for(auto&i : B) cin >>i;

    int rm = c, m = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        if (find(A.begin(), A.end(), i) != A.end()) cnt++;
        if(find(B.begin(), B.end(), i)!= B.end()) cnt++;

        if(cnt == 2) rm--, m++;
    }

    /*
    for(int i= 1; i <= rm; i++){
        for(int j = 1; j <= rm; j++){
            solve(i, j);
        }
    }
    */

    cout << setprecision(15);
    cout << solve(rm, rm, m);
}