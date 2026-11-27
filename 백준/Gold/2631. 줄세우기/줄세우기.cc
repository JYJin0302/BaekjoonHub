#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> base(n);
    for(auto& i : base) cin >> i;
    
    vector<int> dp(n);
    
    for (int i = 0; i < n; i++){
        int temp = 0;
        for (int j = 0; j < i; j++){
            if (base[j] < base[i]) temp = max(temp, dp[j]);
        }
        dp[i] = temp+1;
    }
    
    cout << n - *max_element(dp.begin(), dp.end());
}