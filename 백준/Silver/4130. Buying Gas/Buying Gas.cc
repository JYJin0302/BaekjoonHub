#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, d;
    cin >> n >> m >> d;
    
    n*= 10;
    
    vector<pair<int, int>> A(m+2);
    A[0] = {0, 0};
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        A[i] = {a, b};
    }
    A[m+1] = {d, 0};
    sort(A.begin(), A.end());
    
    int idx = 0, cnt = 0;
    while(idx <= m){
        
        int nidx = idx;
        for(int i = idx + 1; i <= m+1; i++){
            if (A[i].first - A[idx].first <= n) nidx = i;
            else break;
        }
        
        if (nidx == idx) break;
        idx = nidx;
        cnt++;
    }
    
    if (idx == m+1){
        cout << cnt-1;
    }
    else cout << -1;
}