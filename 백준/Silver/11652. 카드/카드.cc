#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    int anslen = 1;
    int cnt = 1;
    ll ans = A[0];
    
    for (int i = 1; i < n; i++){
        if (A[i-1] == A[i]) cnt++;
        else{
            if (cnt > anslen){
                anslen = cnt;
                ans = A[i-1];
            }
            cnt = 1;
        }
    }
    
    if (cnt > anslen){
        anslen = cnt;
        ans = A[n-1];
    }
    
    cout << ans;
}