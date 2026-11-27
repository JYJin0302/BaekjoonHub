#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int r = 0;
    for(int i = 0; i < n; i++){
        vector<int> A(m);
        for(auto& i : A) cin >> i;
        
        int t = A[m-1];
        for (int j = m-2; j >= 0; j--){
            if (A[j] > t) t = A[j];
            else t = A[j] - 1;
        }
        r ^= t;
    }
    
    if (r != 0) cout << "koosaga";
    else cout << "cubelover";
}