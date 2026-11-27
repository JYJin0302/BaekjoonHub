#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int logn = log2(n-1)+1;
    cout << logn << '\n';
    for (int i = 0; i < logn; i++){
        
        vector<int> tmp;
        for (int j = 1; j <= n; j++){
            if (j & (1 << i)) tmp.push_back(j);
        }
        
        cout << tmp.size() << ' ';
        for(int x : tmp) cout << x << ' ';
        cout << '\n';
    }
}