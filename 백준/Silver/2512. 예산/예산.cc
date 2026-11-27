#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    cin >> k;
    
    int ans = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++){
        if (k/(n-i) >= A[i]){
            k -= A[i];
            ans = A[i];
        }
        else{
            ans = k / (n-i);
            break;
        }
    }
    cout << ans;
}