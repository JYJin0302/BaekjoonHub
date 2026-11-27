#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll c, ll d){
    
    int zero_cnt = 0;
    zero_cnt += (a == 0);
    zero_cnt += (b == 0);
    zero_cnt += (c == 0);
    zero_cnt += (d == 0);
    
    if (zero_cnt >= 3){
        return a + b + c + d + 1;
    }
    if (zero_cnt == 2){
        ll res = 0;
        if (a != 0 && b != 0) res = a + 2*b;
        else if (a != 0 && c != 0) {
            if (a == 1) res = 2*c + 1;
            else res = a + 3*c;
        }
        else if (a != 0 && d != 0){
            if (a == 1) res = 2*d + 1;
            else if (a == 2) res = 3*d + 2;
            else res = a + 4*d;
        }
        else if (b != 0 && c != 0) {
            if (b == 1) res = 2*c + 1;
            else res = 2*b + 3*c - 2;
        }
        else if (b != 0 && d != 0) res = b + 2*d;
        else if (c != 0 && d != 0){
            if (d == 1) res = 2*c + 1;
            else if (c == 1) res = 2*d + 1;
            else if (c == 2) res = 3*c + 4*d - ((3*c+4*d) /4 + 1) - 2;
            else res = 3*c + 4*d - 6;
        }
        
        return res + 1;
    }
    if (zero_cnt == 1){
        ll res = 0;
        if (d == 0) res = a + 2*b + 3*c;
        else if (c == 0) res = a + 2*b + 4*d;
        else if (b == 0){
            if (d == 1){
                if (a == 1) res = 3*c + 3;
                else  res = a + 3*c + 4;
            }
            else{
                if (a == 1){
                    if (c == 1) res = 3*d + 3;
                    else res = 3*c + 4*d - 1;
                }
                else res = a + 3*c + 4*d;
            }
        }
        else if (a == 0) res = 2*b + 3*c + 4*d - 2;
        
        return res + 1;
    }
    
    return a + 2*b + 3*c + 4*d + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << '\n';
    }
}