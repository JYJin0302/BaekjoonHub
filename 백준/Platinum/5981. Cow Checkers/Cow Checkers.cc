#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    
    vector<int> A(n+1, -1);
    A[0] = 0;
    int pv = 1;
    for (int i = 1; i <= n; i++){
        if (A[i] == -1){
            int j = i + pv;
            pv++;
            A[i] = j;
            if (j <= n) A[j] = i;
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        
        int a, b;
        cin >> a>> b;
        if (a > b) swap(a, b);
        
        if (A[a] != b) cout << "Bessie\n";
        else cout << "Farmer John\n";
    }
}