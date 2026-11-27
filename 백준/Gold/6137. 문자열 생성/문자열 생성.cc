#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<char> A(n);
    for(auto& i : A) cin >> i;
    
    int l = 0, r = n-1;
    int cnt = 0;
    while(l <= r){
        
        int tl = l, tr = r;
        while(tl < tr && A[tl] == A[tr]) tl++, tr--;
        if (A[tl] > A[tr]) {
            cout << A[r];
            r--;
        }
        else {
            cout << A[l];
            l++;
        }
        cnt++;
        if (cnt == 80) cout << '\n';
        cnt %= 80;
    }
    
}