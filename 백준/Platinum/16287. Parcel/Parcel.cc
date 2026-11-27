#include <bits/stdc++.h>
using namespace std;

bool isIn[800001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int w, n;
    cin >> w >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    bool ok = 0;
    for (int i = 0; i < n; i++){
        for (int j = n-1; j > i; j--){
            int tx = A[i] + A[j];
            if (w - tx >= 0 && isIn[w-tx]) ok = 1;
        }
        for(int j = i-1; j >= 0; j--){
            isIn[A[i] + A[j]] = 1;
        }
    }
    
    if (ok) cout << "YES";
    else cout << "NO";
    
}