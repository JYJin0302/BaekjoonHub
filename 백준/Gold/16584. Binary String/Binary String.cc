#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll val(string s){
    
    reverse(s.begin(), s.end());
    
    ll base = 1, res = 0;
    
    for (auto k : s){
        res += base * (k - '0');
        base *= 2;
    }
    return res;
}

string del_str(string s){
    
    int n = s.size();
    int idx = 0;
    for (idx = 0; idx < n; idx++){
        if (s[idx] != '1') break;
    }
    
    if (idx == n || idx != 1){
        return s.substr(1, n);
    }
    
    for (; idx < n; idx++){
        if (s[idx] != '0') break;
    }
    
    if (idx == n){
        return s.substr(0, n-1);
    }
    
    return s.substr(0, idx) + s.substr(idx + 1, n);

}

int main(){
    
    ll k;
    cin >> k;
    
    string s;
    cin >> s;
    
    int cnt = 0;
    while(val(s) > k) {
        cnt++;
        s = del_str(s);
    }
    
    cout << cnt;
    
}