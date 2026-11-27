#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int ans = 0;
    string s;
    for(int i = 0; i < 8; i++){
        cin >> s;
        for (int j =0; j<8; j++){
            if ((i + j)%2==0 && s[j] !='.') ans++;
        }
    }
    cout << ans;
}