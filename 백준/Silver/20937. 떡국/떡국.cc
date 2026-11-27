#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, ans = 0, val = 0;
    cin >> n;
    
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
        
        if (cnt[a] > val) ans = a, val = cnt[a];
    }
    
    cout << val;
}