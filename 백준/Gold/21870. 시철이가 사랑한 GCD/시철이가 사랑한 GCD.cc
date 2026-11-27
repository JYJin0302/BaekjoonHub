#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a, a);
    
}

int n;
vector<ll> A;

ll solve(int l, int r){
    
    if (l == r) return A[l];
    
    int mid = (l+r-1)/2;
    
    ll g1 = A[l];
    for (int i = l+1; i <= mid; i++) g1 = gcd(g1, A[i]);
    
    ll g2 = A[mid+1];
    for (int i = mid+1; i <= r; i++) g2 = gcd(g2, A[i]);
    
    return max(g1 + solve(mid+1, r), g2 + solve(l, mid));
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    A = vector<ll>(n);
    for(auto& i : A)cin >> i;
    
    cout << solve(0, n-1);    
}