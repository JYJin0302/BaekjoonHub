#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int a, p;
    cin >> a >> p;
    
    map<int, int> C;
    int cnt = 0;
    while(C[a] == 0){
        cnt++;
        C[a] = cnt;
        
        // new a
        int na = 0;
        while(a){
            int ta = a% 10, tb = 1;
            for (int i = 0; i < p; i++) tb *= ta;
            na += tb;
            a /= 10;
        }
        a = na;
    }
    
    cout << C[a] - 1;
}