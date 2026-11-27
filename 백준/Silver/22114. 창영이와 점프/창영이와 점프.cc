#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    n--;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    vector<int> ans;
    int val = 1;
    for (int i = 0; i < n; i++){
        if (A[i] <= k) val++;
        else ans.push_back(val), val = 1;
    }
    
    ans.push_back(val);
    
    int res = ans[0];
    
    for(int i = 1; i < ans.size(); i++){
        res = max(res, ans[i] + ans[i-1]);
    }
    
    cout << res;
    
}