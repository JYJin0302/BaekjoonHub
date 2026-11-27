#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    vector<ll> A(21);
    A[0] = 1;
    A[1] = 0;
    A[2] = 1;
    for(int i = 3; i <= 20; i++){
        A[i] = (i-1) * (A[i-1] + A[i-2]);
    }
    
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        cout << A[a] << '\n';
    }
}