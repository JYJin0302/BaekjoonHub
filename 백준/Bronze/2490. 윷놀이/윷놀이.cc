#include <bits/stdc++.h>
using namespace std;

int main(){
    char c[] = {'E', 'A', 'B', 'C', 'D'};
    
    for(int i = 0 ; i< 3 ;i ++){
        int v = 0;
        for(int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            v += 1 - x;
        }
        cout << c[v] << '\n';
    }
}