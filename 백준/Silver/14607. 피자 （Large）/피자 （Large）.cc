#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> dp;
ll solve(ll n){
    if (dp[n] != 0) return dp[n];
    if (n == 1) return 0;
    ll a = n/2, b = n-a;
    return dp[n] = a*b + solve(a) + solve(b);
}

int main(){
    ll n;
    cin >> n;
    cout << solve(n);
}