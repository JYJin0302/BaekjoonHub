#include <bits/stdc++.h>
using namespace std;

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> money(n);
    for (auto& i : money) cin >> i;
    
    vector<vector<int>> table;
    for (int i = 0; i < k; i++){
        vector<int> temp(3);
        for(auto& j : temp) cin >> j;
        table.push_back(temp);
    }
    
    sort(table.begin(), table.end(), sortcol);
    
    vector<int> dp(k);
    for (int i = 0; i < k; i ++){
        for (int j = 0; j < i; j++){
            if (table[i][0] >= table[j][1])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += ((table[i][1] - table[i][0]) * money[table[i][2] - 1]);
    }
    
    cout << *max_element(dp.begin(), dp.end());
    
}