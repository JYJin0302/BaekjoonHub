#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int d, n;
    cin >> d >> n;
    
    vector<int> depth(d);
    for (int i = 0; i < d; i++){
        int x;
        cin >> x;
        if (i == 0) depth[i] = x;
        else depth[i] = min(depth[i-1], x);
    }
    
    vector<int> N(n);
    for(auto&i : N) cin>>i;
    
    int ni = 0;
    for (int i = d-1; i >= 0; i--){
        if (depth[i] >= N[ni]){
            ni++;
            if (ni == n) {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << 0;
}