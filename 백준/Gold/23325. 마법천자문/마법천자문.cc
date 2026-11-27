#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int num(char c){
    if (c == '+') return 10;
    return 1;
}

int cal(int n1, char c, int n2){
    if (c == '+') return n1 + n2;
    return n1 - n2;
}

int main(){
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector<int> dp(n, -INF);
    
    for(int i = 0; i < n; i++){
        if (i == 0) dp[0] = num(s[i]);
        else if (i == 1){
            if (s[i] == '-' && s[i-1] == '+') dp[1] = 11;
        }
        else if (i == 2){
            dp[i] = cal(dp[0], s[i-1], num(s[i]));
        }
        else{
            dp[i] = max(cal(dp[i-2], s[i-1], num(s[i])), -INF);
            if (s[i] == '-' && s[i-1] == '+') dp[i] = max(dp[i], cal(dp[i-3], s[i-2], 11));
        }
    }
    
    cout << dp[n-1];
}