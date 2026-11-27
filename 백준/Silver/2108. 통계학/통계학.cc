#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    map<int, int> cnt;
    ll s = 0;
    int mcnt = 0;
    for(auto i : A) {
        s += i, cnt[i]++;
        mcnt = max(mcnt, cnt[i]);
    }
    
    vector<int> k;
    for(auto i : A) {
        if (cnt[i] == mcnt && (k.empty() || k.back() != i)) k.push_back(i);
    }
    
    
    double a1 = int(round(s*1.0 / n));
    
    
    ll a2 = A[n/2];
    ll a3 = 0;
    if (k.size() > 1) a3 = k[1];
    else a3 = k[0];
    
    ll a4 = A[n-1] - A[0];
    
    cout << a1 << '\n' << a2 << '\n' << a3 << '\n' << a4;
}