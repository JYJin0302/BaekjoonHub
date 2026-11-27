#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    vector<bool> v(n+1);
    int c = 1, r = A[0];
    
    vector<vector<int>> ans;
    
    vector<int> tmp;
    for (int i = 0; i < n; i++){
        if (A[i] > r){
            if (c > r){
                sort(tmp.begin(), tmp.end());
                ans.push_back(tmp);
                tmp.clear();
            }
            
        }
        tmp.push_back(A[i]);
        r = max(r, A[i]);
        v[A[i]]=1;
        while(v[c]) c++;
    }
    
    if(!tmp.empty()) {
        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }
    
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.size() << ' ';
        for (int j : i) cout << j << ' ';
        cout << '\n';
    }
}