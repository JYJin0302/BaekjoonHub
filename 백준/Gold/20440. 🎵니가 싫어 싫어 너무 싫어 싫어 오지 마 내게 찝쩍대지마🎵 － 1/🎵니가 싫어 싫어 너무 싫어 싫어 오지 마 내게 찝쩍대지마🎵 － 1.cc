#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> A;
    for(int i = 0; i < n; i++){
        
        int a, b;
        cin >> a >> b;
        
        A.push_back({a, 1});
        A.push_back({b, -1});
    }
    
    sort(A.begin(), A.end());
    
    int ans = 0, al = -1, ar = -1;
    int cv = 0, pv = A[0].x;
    bool s = 0;
    
    int idx = 0;
    while(idx < n*2){
        
        int ci = idx;
        while(idx < n*2 && A[idx].x == A[ci].x){
            cv += A[idx].y;
            idx++;
        }
        
        if (cv > ans) s = 1, ans = cv, al = A[ci].x;
        else if (cv < ans && s) s = 0, ar = A[ci].x;
    }
    
    cout << ans << '\n' << al << ' ' << ar;
}