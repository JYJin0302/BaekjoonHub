#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[0] = n+2;
    for (int i = 1; i <= n; i++){
        int j = i-1;
        while(dp[j] <= i - j + 1){
            j -= dp[j];
        }
        dp[i] = i - j;
    }
    
    if (dp[n] != 1){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        cout << 1 << endl;
        n--;
        while(n) {
            int x;
            cin >> x;
            
            n -= x;
            cout << dp[n] << endl;
            n -= dp[n];
        }
    }
}