#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int ans = 0, v = 0;
    for(int i =1 ; i <=n ;i++){
        vector<int> A(5);
        for(auto& j : A) cin >> j;
        
        int val = 0;
        for(int a = 0; a < 5; a++){
            for (int b = a + 1; b < 5; b++){
                for(int c = b + 1; c < 5; c++){
                    val = max(val, (A[a] + A[b] + A[c])%10);
                }
            }
        }
        
        if (val >= v){
            ans = i;
            v = val;
        }
    }
    
    cout << ans;
}