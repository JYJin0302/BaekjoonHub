#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(A.begin(), A.end());
    
    if (n == 0){
        cout << 0;
        return 0;
    }
    
    int rmv = n * 15 + 50;
    rmv /= 100;

    int rm = n - rmv * 2;
    int tot = 0;
    for (int i = rmv; i < n - rmv; i++) {
        tot += A[i];
    }

    cout << (tot + rm / 2) / rm;
}