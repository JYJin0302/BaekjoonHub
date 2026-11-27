#include <bits/stdc++.h>
using namespace std;



vector<int> dp(100001);
vector<int> sq;

void square(){
    int i = 1;
    while(i*i < 100000){
        sq.push_back(i*i);
        i++;
    }
}

void dp_setup(){
    for (int i = 1; i < 100001; i++) dp[i] = i;
    for (int i : sq){
        if (i== 1) continue;
        for (int j = i; j < 100001; j++){
            dp[j] = min(dp[j], dp[j - i] + 1);
        }
    }
}


int main(){
    int n;
    cin >> n;
    
    square();
    dp_setup();
    
    cout << dp[n];
    
}