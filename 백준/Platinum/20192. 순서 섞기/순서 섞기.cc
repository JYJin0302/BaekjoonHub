#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    bool p = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (A[i] < A[i-1] && p){
            p = 0;
        }
        else if (A[i] > A[i-1] && !p){
            cnt++;
            p = 1;
        }
    }
    
    if (cnt == 1 && p) {
        cout << 0;
        return 0;
    }
    
    int ans = 0;
    while(cnt > 1){
        ans++;
        cnt = (cnt + 1) / 2;
    }
    if (cnt == 1) ans++;
    
    cout << ans;
    
}