#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> A(m);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    int cnt = 0;
    for(int i : A){
        if (i > n) break;
        cnt++;
        n -= i;
    }
    cout << cnt;
}