#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a > b) swap(a,b );
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    
    int n[5];
    for(int i = 0; i < 5; i++) cin >> n[i];
    
    int ans = 1e9;
    for(int i = 0; i < 5; i++){
        for (int j = i+1; j < 5; j++){
            for(int k = j + 1; k < 5; k++){
                int x= n[i]*n[j] /gcd(n[i], n[j]);
                ans = min(ans, x*n[k] / gcd(x, n[k]));
            }
        }
    }
    cout << ans;
    
}