#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int a, b;
    cin >> a >> b;
    
    int cnt = 0;
    for(int i : A) cnt += (i >= b);
        
    cout << n*a/100 << ' ' << cnt;
    
}