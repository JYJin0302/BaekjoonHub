#include <bits/stdc++.h>
using namespace std;

struct P{
    int x, y, z;
};

int main(){
    
    int n, k;
    cin >> n >> k;
    
    int f = -1;
    vector<P> A(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a == k) f = i;
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (i == f) continue;
        if (A[i].x > A[f].x || (A[i].x == A[f].x && A[i].y > A[f].y) || (A[i].x==A[f].x && A[i].y==A[f].y && A[i].z > A[f].z)) ans++;
        
    }
    cout << ans+1;
}