#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    vector<bool> v(n);
    v[0] = 1;
    
    int i = 0;
    int cnt = 0;
    while(1){
        i = A[i];
        if (v[i]) {
            cout << -1;
            return 0;
        }
        v[i] = 1;
        cnt++;
        if (i == k) break;
    }
    cout << cnt;
}