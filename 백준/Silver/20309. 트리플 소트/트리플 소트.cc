#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        A[i] = {x, i};
    }
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n; i++){
        if (abs(A[i].second - i) % 2 == 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}