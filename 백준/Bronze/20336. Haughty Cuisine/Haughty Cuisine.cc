#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        int d;
        cin >> d;
        if (i == 0) cout << d <<  '\n';
        
        for(int j = 0; j < d; j++){
            string s;
            cin >> s;
            if (i == 0) cout << s << '\n';
        }
    }
}