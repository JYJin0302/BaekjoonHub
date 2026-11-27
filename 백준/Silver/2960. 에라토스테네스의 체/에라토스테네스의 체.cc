#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n+1);
    int cnt = 0;
    
    for (int i = 2; i <= n ;i ++){
        if (A[i] == 0){
            for (int j = i; j <= n; j += i){
                cnt += 1 - A[j];
                A[j] = 1;
                if (cnt == k){
                    cout << j;
                    return 0;
                }
            }
        }
    }
}