#include <bits/stdc++.h>
using namespace std;

int dp1[100001];
int dp2[100001];

int main(){
    int n;
    cin >> n;
    dp1[1] = 2;
    dp1[2] = 4;
    dp2[1] = 3;
    dp2[2] = 7;
    
    for(int i = 3; i <= n; i++){
        dp1[i] = (dp1[i-1] + dp2[i-2] * 2) % 9901;
        dp2[i] = (2*dp1[i-1] + 3*dp2[i-2]) % 9901;
    }
    
    cout << dp2[n];
    
}