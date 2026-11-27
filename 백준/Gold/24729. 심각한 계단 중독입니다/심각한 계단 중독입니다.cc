#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> cnt(100001);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    int l = 0, r = 100000;
    while(cnt[l] == 0) l++;
    while(cnt[r] == 0) r--;
    
    if (n %2== 1){
        cout << -1;
        return 0;
    }
    if (r == l + 1){
        if (cnt[l] == cnt[r]) cout << 1;
        else cout << -1;
        return 0;
    }
    
    bool ok = 1;
    cnt[l+1] -= cnt[l] + 1;
    if (cnt[l+1] < 0) ok = 0;
    
    for (int i = l+2; i < r; i++){
        cnt[i] -= cnt[i-1] + 2;
        if (cnt[i] < 0) ok = 0;
    }
    
    cnt[r] -= cnt[r-1] + 1;
    if (cnt[r] != 0) ok = 0;
    
    if (ok) cout << 1;
    else cout << -1;
}