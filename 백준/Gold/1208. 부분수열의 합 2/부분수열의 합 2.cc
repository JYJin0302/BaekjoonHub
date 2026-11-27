#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n);
    for(auto& i: A) cin >> i;
    
    int tn = n/2;
    
    map<int, int> cnt;
    for (int i = 0; i < (1 << tn); i++){
        
        int temp = 0;
        
        for (int j = 0; j < tn; j++){
            if (i & (1 << j)) temp += A[j];
        }
        
        cnt[temp]++;
    }
    
    ll ans = 0;
    for (int i = 0; i < (1 << n - tn); i++){
        
        int temp = 0;
        
        for (int j = 0; j < n - tn; j++){
            if (i & (1 << j)) temp += A[tn + j];
        }
        
        ans += cnt[m - temp];
    }
    
    if (m == 0) ans--;
    cout << ans;
    
}