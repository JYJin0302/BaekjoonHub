#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    int a = n/2, b = n-a;
    if (a*b < k){
        cout << -1;
        return 0;
    }
    
    string s = string(a, 'A') + string(b, 'B');
    int v = a*b;
    
    while(v > k){
        
        for (int i =1 ; i < s.size(); i++){
            if (s[i] == 'B' && s[i-1] == 'A'){
                swap(s[i], s[i-1]);
                break;
            }
        }
        v--;
    }
    cout << s;
}