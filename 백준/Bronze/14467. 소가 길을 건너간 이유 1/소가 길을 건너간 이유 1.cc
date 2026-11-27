#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> base(11, -1);
    int n, a, b, ans = 0;
    cin >> n;
    while(n--){
        cin >> a>>b;
        if (base[a] != -1 && base[a] != b) ans++;
        base[a] = b;
    }
    cout << ans;   
}