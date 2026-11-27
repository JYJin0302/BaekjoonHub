#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    map<int, pair<int, int>> A;
    
    int pre_val = 0, pre_cnt = 1;
    for (int i = 0; i < n; i++){
        
        int m;
        cin >> m;
        
        A[m].x++;
        
        if (pre_val >= m){
            pre_cnt++;
        }
        pre_val = m;
        
        if (A[m].y == 0) A[m].y = pre_cnt;
        
    }
    
    cout << A.size() << '\n';
    for (auto k : A){
        cout << k.x << ' ' << k.y.x << ' ' << 1000001 - k.y.y << '\n';
    }
}