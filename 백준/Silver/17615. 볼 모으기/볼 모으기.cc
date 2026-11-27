#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int cntR = 0, cntB = 0;
    for(char c : s){
        if (c == 'R') cntR++;
        else cntB++;
    }
    
    int ansR = n+1;
    int ri = 0;
    while(ri < n && s[ri] == 'R') ri++;
    ansR = min(ansR, cntR - ri);
    ri = n-1;
    while(ri >= 0 && s[ri] == 'R') ri--;
    ansR = min(ansR, cntR - (n-1 - ri));
    
    int ansB = n+1;
    ri = 0;
    while(ri < n && s[ri] == 'B') ri++;
    ansB = min(ansB, cntB - ri);
    ri = n-1;
    while(ri >= 0 && s[ri] == 'B') ri--;
    ansB = min(ansB, cntB - (n-1 - ri));
    
    cout << min(ansR, ansB);
}