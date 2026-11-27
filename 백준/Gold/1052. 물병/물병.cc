#include <bits/stdc++.h>
using namespace std;

bool isB(int x, int i){
    return (x & (1 << i)) > 0;
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    int cnt = 0;
    for (int i = 0; i < 25; i++){
        cnt += isB(n, i);
    }
    
    if (cnt <= k) {
        cout << 0;
        return 0;
    }
    
    int tn = n;
    int i = 0;
    while(i < 26){
        if (isB(n, i)) n += (1 << i);
        
        cnt = 0;
        for (int j = 0; j < 25 ;j ++){
            cnt += isB(n, j);
        }
        if (cnt <= k){
            cout << n - tn;
            return 0;
        }
        i++;
    }
}