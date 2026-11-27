#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>A(n+1);
    A[1] = 1;
    for (int i = 2; i <= n; i++) A[i] = A[i-1] + A[i-2];
    
    cout << A[n];
}