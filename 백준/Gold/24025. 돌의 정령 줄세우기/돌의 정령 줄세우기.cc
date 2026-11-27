#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    if (A[n-1] < 0) {
        cout << -1;
        return 0;
    }
    
    int n1 = 1, n2 = n;    
    for(int i : A){
        if (i > 0) {
            cout << n2 << ' '; n2--;
        }
        else {
            cout << n1 << ' '; n1++;
        }
    }
}