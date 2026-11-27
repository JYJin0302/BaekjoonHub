#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int cnt1 = 0, cnt0 = 0;
    for(char i : s) {
        if (i == '1') cnt1++;
        else cnt0++;
    }
    cnt1 /= 2;
    cnt0 /= 2;
    
    int c1 = 0, c0 = 0;
    for(char i : s){
        if (i == '1'){
            if (c1 < cnt1) c1++;
            else cout << i;
        }
        else{
            if (c0 < cnt0) cout << i;
            c0++;
        }
    }
    
    
}