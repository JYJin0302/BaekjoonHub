#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int ans = 30001;
    int L = *max_element(A.begin(), A.end()), R = 30000;
    
    while(L <= R){
        
        int mid = (L+R)/2;
        
        int val = 0, cnt = 0;
        for (int i = 0; i < n; i++){
            val += A[i];
            if (val > mid) {
                val = A[i];
                cnt++;
            }
        }
        cnt++;
        
        if (cnt > m){
            L = mid+1;
        }
        else {
            ans = min(ans, mid);
            R = mid - 1;
        }
    }
    
    cout << ans << '\n';
    
    vector<int> res;
    int cnt = 0, val = 0;
    for (int i = 0; i < n; i++){
        val += A[i];
        cnt++;
        if (val > ans){
            res.push_back(cnt - 1);
            cnt = 1;
            val = A[i];
        }
    }
    
    res.push_back(cnt);
    
    int nd = m - res.size();
    
    for (int i : res){
        while(nd && i > 1){
            cout << "1 ";
            i--;
            nd--;
        }
        cout << i << ' ';
    }
    
}