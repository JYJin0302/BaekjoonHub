#include <bits/stdc++.h>
using namespace std;

int A[101][101];
int B[101][101];

int main(){
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    
    int k;
    cin >> m >> k;
    
    for(int i = 0 ;i < m; i++){
        for (int j = 0; j < k; j++){
            cin >> B[i][j];
        }}
    
    for(int i = 0; i < n; i++){
for (int j = 0; j < k; j++){
    int val = 0;
    for (int x = 0; x < m; x++){
        val += A[i][x] * B[x][j];
    }
    cout << val << ' ';
}
    cout << '\n';}
    
}