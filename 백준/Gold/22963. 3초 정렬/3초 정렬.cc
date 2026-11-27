#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n), idx(n);
    for(auto& i : A) cin >> i;
    
    vector<int> lis;
    
    for (int i = 0; i < n; i++){
        int num = A[i];
        int ix = upper_bound(lis.begin(), lis.end(), num) - lis.begin();
        if (ix == lis.size()) lis.push_back(num);
        else lis[ix] = num;
        idx[i] = ix;
    }
    
    int ans = n - lis.size();
    if (ans > 3){
        cout << "NO";
        return 0;
    }
    else cout << "YES\n" << ans << '\n';
    
    
    int maxl = lis.size()-1, pre = 1000000000;
    vector<bool> used(n);
    
    for(int i = n-1; i >= 0; i--){
        if (A[i] <= pre && idx[i] == maxl){
            used[i] = 1;
            pre = A[i];
            maxl--;
        }
    }
    
    pre = 1;
    for(int i = 0; i < n; i++){
        if (!used[i]){
            cout << i+1 << ' ' << pre << '\n';
        }
        else pre = A[i];
    }
}