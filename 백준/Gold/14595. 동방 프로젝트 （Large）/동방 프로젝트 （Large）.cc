#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;    
    
    vector<pair<int, int>> A;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        A.push_back({a, b});
    }
    A.push_back({n+1, n+1});
    sort(A.begin(), A.end());
    
    int l = 0, r = 0;
    int ans = 0;
    for(auto i : A){
        if (i.x <= r) r = max(r, i.y);
        else{
            ans += (r - l > 0);
            ans += i.x - r - 1;
            l = i.x;
            r = i.y;
        }
    }
    
    cout << ans;
}