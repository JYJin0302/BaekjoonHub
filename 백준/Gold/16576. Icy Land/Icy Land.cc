
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[505][505];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >>n >>m;


    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            cin >>A[i][j];
        }
    }

    if(n == 1){

        int cnt = 0;
        for(int i = 1; i < m-1; i++) {
            if (A[0][i] == '.')cnt++;
        }
        cout <<cnt;
        return 0;

    }

    if (m == 1){
        int cnt = 0;
        for(int i = 1; i < n-1; i++) {
            if (A[i][0] == '.')cnt++;
        }
        cout <<cnt;
        return 0;

    }

    if (n == 2){
        int cnt = 0;
        for(int i = 1; i < m-1; i++) {
            if (A[0][i] == '.' && A[1][i] == '.')cnt++;
        }
        cout <<cnt;
        return 0;

    }

    if (m == 2){
        int cnt = 0;
        for(int i = 1; i < n-1; i++) {
            if (A[i][0] == '.' && A[i][1] == '.')cnt++;
        }
        cout <<cnt;
        return 0;

    }

    int cnt = 0;
    for(int i = 1; i <n-1; i++){
        for(int j = 1; j <m-1; j++){
            if(A[i][j] == '.') {
                    cnt++;
                    A[i][j] = '#';
            }
        }
    }

    bool ok = 0;
    for(int i = 1; i < n-1; i++){
        if(A[i][0] == '#') ok = 1;
        if (A[i][m-1] == '#') ok = 1;
    }
    for(int j = 1; j < m-1; j++){
        if(A[0][j] == '#') ok = 1;
        if(A[n-1][j] == '#') ok = 1;
    }

    if(!ok)cnt++;
    cout <<cnt;

    return 0;
}
