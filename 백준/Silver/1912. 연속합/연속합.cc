#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, inp;
    cin >> n;

    vector<int> base(n);
    int maxneg = -1000;
    for (int i = 0; i < n; i++) {
        cin >> base[i];
        if (base[i] <= 0) maxneg = max(maxneg, base[i]);
    }
    
    vector<int> dp(n);
    dp[0] = base[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1], 0) + base[i];
    }
    cout << *max_element(dp.begin(), dp.end());

}