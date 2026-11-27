#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m;
    cin >> m;
    
    int a, b;
    cin >> a >> b;
    
    vector<pair<int, int>> A;
    while(a != 0 || b != 0){
        if (a > b) swap(a, b);
        if (a <= m && b >= 0){
            a = max(0, a);
            b = min(m, b);
            A.push_back({a, b});
        }
        cin >> a >> b;
    }
    
    sort(A.begin(), A.end());
    
    int n = A.size();
    int r = 0, ans = 0;
    int ix = 0;
    while(ix < n && r < m){
        
        int v = r;
        while(ix < n && A[ix].x <= r) {
            v = max(v, A[ix].y);
            ix++;
        }
        
        if (v != r) {
            ans++;
            r = v;
        }
        else break;
    }
    
    if (r == m) cout << ans;
    else cout << 0;
}