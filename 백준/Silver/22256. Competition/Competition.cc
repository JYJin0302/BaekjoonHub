#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    
    vector<int> A(n), B(n), C(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    
    for(int i= 0 ; i < n; i++) C[i] = B[i] - A[i];
        
    sort(C.rbegin(), C.rend());
    
    int tot = 0;
    for(int i : A) tot += i;
    
    for (int i = 0; i < b; i++) tot += C[i];
    
    cout << tot;
}