#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A(6);
    for(auto& i : A) cin >> i;
    
    int ans = 0;
    ans += A[5];
    
    
    ans += A[4];
    A[0] = max(0, A[0] - A[4] * 11);
    
    ans += A[3];
    int max2 = min(A[1], 5 * A[3]);
    A[1] -= max2;
    int max1 = min(A[0], 20 * A[3] - max2 * 4);
    A[0] -= max1;
    
    ans += A[2] / 4;
    A[2] %= 4;
    
    if (A[2] != 0){
        ans++;
       max2 = min(7 - 2*A[2], A[1]);
        A[1] -= max2;
        A[0] = max(0, A[0] - (36 - 9*A[2] - max2 * 4));
    }
    
    ans += A[1] / 9;
    A[1] %= 9;
    
    if (A[1] != 0){
        ans++;
        A[0] = max(0, A[0] - (36 - A[1] * 4));
    }
    
    ans += (A[0] + 35) / 36;
    
    cout << ans;
}