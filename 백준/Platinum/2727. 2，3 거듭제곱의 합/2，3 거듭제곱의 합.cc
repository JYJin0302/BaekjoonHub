#include <bits/stdc++.h>
using namespace std;


int p2, p3;
vector<pair<int,int>> ans;

void solve(int n){
    if (n == 0) return;
    
    int c2 = 0, c3 = 0;
    while(n % 2 == 0){
        n/=2;
        c2++;
    }
    while(n%3 == 0){
        n/=3;
        c3++;
    }
    p2 += c2;
    p3 += c3;
    
    
    int z = 1, c = 0;
    while(z <= n) {
        z *= 2;
        c++;
    }
    z /= 2, c--;
    
    if ((n-z) % 3 == 0) {
        ans.push_back({p2 + c, p3});
        solve(n - z);
    }
    else {
        ans.push_back({p2 + c - 1, p3});
        solve(n - z/2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        p2 = 0, p3 = 0;
        
        solve(n);
        cout << ans.size() << '\n';
        for(auto i : ans) cout << i.first << ' ' << i.second << '\n';
        ans.clear();
    }
}