#include <bits/stdc++.h>
using namespace std;

int n, tx, ty, cx, cy;
double ans;

vector<pair<int, int>> P;

double caldist(){
    return sqrt((double)tx * tx + (double)ty * ty);
}

void select(int cnt = 0, int s = 0){
    
    if (cnt == n/2){
        
        ans = min(ans, caldist());
        return;
    }
    
    for (int i = s; i < n; i++){
        tx -= 2*P[i].first, ty -= 2*P[i].second;
        select(cnt+1, i+1);
        tx += 2*P[i].first, ty += 2*P[i].second;
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << fixed << setprecision(10);
    
    int t;
    cin >> t;
    
    while(t--){
        
        cin >> n;
        
        P = vector<pair<int, int>>(n);
        
        for(auto& i : P) cin >> i.first >> i.second;
        
        tx = 0, ty = 0, cx = 0, cy = 0;
        for (auto i : P)  tx += i.first, ty += i.second;
        
        ans = 400000;
        select();
        
        cout << ans << '\n';
    }
    
}