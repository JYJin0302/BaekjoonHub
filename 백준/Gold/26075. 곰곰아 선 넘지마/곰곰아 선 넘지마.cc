#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> A, B;
    
    string s1, s2;
    cin >> s1 >> s2;
    
    for(int i = 0; i < n+m; i++){
        if (s1[i] == '1') A.push_back(i);
        if (s2[i] == '1') B.push_back(i);
    }
    
    ll tot = 0;
    for(int i = 0; i < m; i++){
        tot += abs(A[i] - B[i]);
    }

    ll a = tot/2, b = tot-a;
    cout << a*a + b*b;
}