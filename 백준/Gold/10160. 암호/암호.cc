#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T{
    //      A, AB,  ABA, ABC,ABAB,ABCB,  C
    ll x0, x1, x2, x31, x32, x41, x42;
};

int main(){
    
    ll n, k;
    cin >> n >> k;
    
    const ll mod = 1e9+9;
    
    T p, tmp;
    
    p = {k-1, 1, 0, 0, 0, 0};
    
    for (int i = 2; i <= n; i++){
        tmp.x0 = (p.x0 + p.x1 + p.x2 + p.x31 + p.x32 + p.x41 + p.x42) * (k-3) % mod; // a, b, c 제외 전부
        tmp.x0 += p.x0 * 2 + p.x1 + p.x2 + p.x31 + p.x32 + p.x41 + p.x42;
        tmp.x0 %= mod;
        
        tmp.x1 = (p.x0 + p.x1 + p.x31 + p.x32 + p.x42) % mod; 
        
        tmp.x2 = p.x1;
        tmp.x31 = (p.x2 + p.x41) % mod;
        tmp.x32 = p.x2;
        
        tmp.x41 = p.x31;
        tmp.x42 = p.x32;
        
        swap(p, tmp);
    }
    
    cout << (p.x0 + p.x1 + p.x2 + p.x31 + p.x32 + p.x41 + p.x42) % mod;
}