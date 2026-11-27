#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    vector<int> dp;
    for(int i : A){
        int ix = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        
        if (ix == dp.size()) dp.push_back(i);
        else dp[ix] = i;
    }
    
    cout << n - dp.size();
}