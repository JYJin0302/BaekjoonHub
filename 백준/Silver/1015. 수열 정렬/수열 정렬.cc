#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i ++){
        int a;
        cin >> a;
        
        A[i] = {a, i};
    }
    sort(A.begin(), A.end());
    
    vector<int> ans(n);
    for (int i = 0; i < n;i ++){
        ans[A[i].second] = i;
    }
    
    for(auto i : ans) cout << i << ' ';    
    
}