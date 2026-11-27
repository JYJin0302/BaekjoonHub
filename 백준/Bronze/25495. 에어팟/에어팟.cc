#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int val = 2, pv = 2;
    for (int i = 1; i < n; i++){
        if (A[i] == A[i-1] && val != 0){
            val += pv*2;
            pv *= 2;
        }
        else val += 2, pv = 2;
        
        if (val >= 100){
            val = 0, pv = 2;
        }
    }
    cout << val;
}