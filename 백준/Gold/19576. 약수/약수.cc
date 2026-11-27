#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int>A(n);
    for(auto& i : A)cin>>i;
    
    sort(A.begin(), A.end());
    
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        int temp = 0;
        for (int j = 0; j < i; j++){
            if (A[i] % A[j] == 0){
                temp = max(temp, dp[j]);
            }
        }
        dp[i] = temp + 1;
    }
    cout << n - *max_element(dp.begin(), dp.end());
}