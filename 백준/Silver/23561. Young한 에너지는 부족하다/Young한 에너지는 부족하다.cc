#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n*3);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    cout << A[n*2-1] - A[n];
}