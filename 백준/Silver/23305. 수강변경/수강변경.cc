#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    map<int, int> A, B;
    for(int i = 0 ;i < n; i++){
        int x;
        cin >> x;
        A[x]++;
    }
    for(int i = 0 ;i < n; i++){
        int x;
        cin >> x;
        B[x]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= 1000000; i++){
        ans += min(A[i], B[i]);
    }
    cout << n - ans;
}