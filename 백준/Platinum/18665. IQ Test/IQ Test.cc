#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, bool> in_set;
void solve(ll n){    
    ll A = ceil(sqrtl(n)), B = A*A - n;    
    if (!in_set[A]) solve(A);
    if (!in_set[B]) solve(B);    
    in_set[n] = 1;
    cout << A << ' ' << B << '\n';
}
int main(){    
    ll n;
    cin >> n;    
    in_set[0] = 1;
    in_set[1] = 1;
    in_set[2] = 1;    
    solve(n);
}