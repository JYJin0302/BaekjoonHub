#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);    
    int n;
    cin >> n;
    vector<pair<int, int>> pol(n);
    for (int i = 0; i < n; i++){
        cin >> pol[i].first >> pol[i].second;
    }
    int x, y;
    cin >> x >> y;
    
    bool N = 1, E = 1,W = 1, S = 1;
    for (int i = 0; i < n; i++){
        int a, b;
        tie(a, b) = pol[i];
        
        int dx = a - x;
        int dy = b - y;
        
        if (dy > 0 && abs(dx) <= abs(dy)) N = 0;
        if (dy < 0 && abs(dx) <= abs(dy)) S = 0;
        if (dx > 0 && abs(dy) <= abs(dx)) E = 0;
        if (dx < 0 && abs(dy) <= abs(dx)) W = 0;
    }
    
    if (N || E || W || S) cout << "YES";
    else cout << "NO";
}