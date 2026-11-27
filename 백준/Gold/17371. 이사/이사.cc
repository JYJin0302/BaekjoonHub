#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define X first
#define Y second

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> A(n);
    for(auto& i : A) cin >> i.X >> i.Y;
    
    int ans = 0;
    double dist = 1000000;
    
    for (int i = 0; i < n; i++){
        
        double mdist = 0;
        for (int j = 0; j < n; j++){
            
            double cdist = sqrt((A[i].X - A[j].X)*(A[i].X - A[j].X) + (A[i].Y - A[j].Y) * (A[i].Y - A[j].Y));
            mdist = max(mdist, cdist);
        }
        
        if (dist > mdist / 2) {
            dist = mdist/2;
            ans = i;
        }
    }
    
    cout << A[ans].X << ' ' << A[ans].Y;
    
}