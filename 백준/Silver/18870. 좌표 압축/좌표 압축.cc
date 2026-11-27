#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a;
    cin >> n;
    
    vector<pair<int ,int>> A(n);
    for (int i = 0; i < n ;i ++){
        cin >> a;
        A[i] = {a, i};
    }
    
    sort(A.begin(), A.end());
    
    vector<int> ans(n);
    ans[A[0].second] = 0;
    for (int i = 1; i < n; i++){
        if (A[i].first == A[i-1].first) ans[A[i].second] = ans[A[i-1].second];
        else ans[A[i].second] = ans[A[i-1].second] + 1;
    }
    for (int i : ans) cout << i << ' ' ;
}