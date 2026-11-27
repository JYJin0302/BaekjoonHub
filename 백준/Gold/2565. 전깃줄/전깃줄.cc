#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, n1, n2;
    cin >> n;
    
    map<int, int> base;
    for (int i = 0; i < n; i++){
        cin >> n1 >> n2;
        base[n1] = n2;
    }
    vector<int> table;
    for (auto i : base) table.push_back(i.second);
    
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        int maxval = 0;
        for (int j = 0; j < i; j++){
            if (table[j] < table[i]) maxval = max(maxval, dp[j]);
        }
        dp[i] = maxval + 1;
    }
    
    cout << n - *max_element(dp.begin(), dp.end());
}