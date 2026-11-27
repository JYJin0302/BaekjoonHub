#include <bits/stdc++.h>
using namespace std;

int GCD(int n, int m){
    while(m){
        int temp = n % m;
        n = m;
        m = temp;
    }
    return n;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> base(n);
    for (auto& i : base) cin >> i;
    
    int t = base[0];
    for (int i = 1; i < n; i++){
        int temp = GCD(max(t, base[i]), min(t, base[i]));
        cout << t/temp << '/' << base[i]/temp << endl;       
    }
}