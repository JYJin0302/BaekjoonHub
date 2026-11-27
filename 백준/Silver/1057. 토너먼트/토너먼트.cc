#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int k, n, m;
    cin >> k >> n >> m;
    
    n--, m--;
    
    int cnt = 0;
    while(n != m){
        cnt++;
        n /= 2, m /=2;
    }
        
    cout << cnt;
}