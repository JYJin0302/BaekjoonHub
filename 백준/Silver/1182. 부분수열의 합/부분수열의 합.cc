#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    
    vector<int> base(n);
    for (auto& i : base) cin >> i;
    
    int ans = 0;
    for (int i = 1; i <= (1 << n) - 1; i++){
        int temp = 0;
        for (int k = 1; k <= n; k++){
            if (i & 1 << (k-1)) temp += base[k-1];
        }
        if (temp == s) ans++;
    }
    cout << ans;

}