#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> A;
    
    for (int i = 0; i < n; i++){
        cin >> a>> b;
        A.push_back({a, b});
    }
    sort(A.begin(), A.end());
    
    int ans = 0;
    for (auto i : A){
        tie(a, b)= i;
        if (a <= ans) ans += b;
        else ans = a + b;
    }
    cout << ans;
}