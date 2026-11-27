#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cnt;
void game(ll x, ll y){
    if (x / y >= 2 || x % y == 0) return;
    cnt++;
    game(y, x%y);
}
int main(){
    ll n, m;
    cin >> n >> m;
    cnt = 0;
    game(max(n, m), min(n, m));
    if (cnt % 2)cout << "lose";
    else cout << "win";
}