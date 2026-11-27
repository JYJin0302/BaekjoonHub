#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

int A[101];
int getCnt(int l, int r){
    if (l > r) return 0;
    int mv = A[l];
    for(int i = l + 1; i <= r; i++){
        mv = min(mv, A[i]);
    }

    int res = 1;
    int pv = l;
    for(int i = l; i <= r; i++){
        if (A[i] == mv) {
            res += getCnt(pv, i-1);
            pv = i+1;
        }
    }
    res += getCnt(pv, r);
    return res;
}

void solve(){

    int n;
    cin >> n;
    for(int i =0 ;i < n; i++){
        cin >> A[i];
    }

    cout << getCnt(0, n-1) << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}