#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin() + 1, A.end());
    
    int t = *max_element(A.begin()+1, A.end());
    
    bool ok = 1;
    for(int i = 1; i < n; i++){
        if (A[0] > A[i]) A[0] += A[i];
        else {
            ok = 0;
            break;
        }
        
        if (A[0] > t) break;
    }
    
    if(ok) cout << "Yes";
    else cout << "No";
}