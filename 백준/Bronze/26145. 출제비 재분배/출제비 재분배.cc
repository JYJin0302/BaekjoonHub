#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> A(n+m);
    for(int i = 0; i < n; i++) cin >> A[i];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n+m; j++){
            int x;
            cin >> x;
            A[i] -= x;
            A[j] += x;
        }
    }
    
    for(int i = 0; i < n+m; i++) cout << A[i] << ' ';
}