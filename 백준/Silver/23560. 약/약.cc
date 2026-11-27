#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> A(n+1);
    A[0] = 1;
    A[1] = 2;
    for(int i = 2; i <= n; i++){
        for (int j = 0; j < i; j++) A[i] += A[j]*2;
    }
    cout << A[n];
}