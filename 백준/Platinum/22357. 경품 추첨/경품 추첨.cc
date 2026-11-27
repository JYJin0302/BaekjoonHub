#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    
    vector<int> A = {1};
    int x = 2;
    while(A.size() < k){
        bool ok = 1;
        for(int i : A){
            if (x/gcd(x,i) < n) ok = 0;
        }
        if(ok)A.push_back(x);
        x++;
    }
    
    for(int i = 0; i < k; i++){
        int x = 1, cnt = 0;
        while(cnt < n){
            cout << x << ' ';
            x += A[i];
            cnt++;
        }
        cout << '\n';
    }
}