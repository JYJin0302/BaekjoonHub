#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    
    int n, m, l, k;
    cin >> n >> m >> l >> k;
    
    vector<pair<int, int>> A(k);
    for(auto& i : A) cin >> i.x >> i.y;
    
    sort(A.begin(), A.end());
    
    int ans = 0;
    for (int i = 0; i < k; i++){
        for (int j = i; j < k; j++){
            
            int a = min(A[i].x, A[j].x);
            int b = min(A[i].y, A[j].y);
            
            int cnt = 0;
            for (int kk = 0; kk < k; kk++){
                if (A[kk].x - a <= l && A[kk].x >= a && A[kk].y - b <= l && A[kk].y >= b) cnt++;
            }
            ans = max(ans, cnt);
        }
        
        
    }
    cout << k - ans;
    
}