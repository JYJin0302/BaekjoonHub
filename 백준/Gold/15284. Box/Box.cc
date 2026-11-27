#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> A(3);
    cin >>A[0] >>A[1] >>A[2];
    sort(A.begin(), A.end());

    ll x, y;
    cin >>x >>y;

    if (x > y)swap(x, y);

    do{

        bool ok = 0;
        ll a, b, c;
        a = A[0];
        b = A[1];
        c = A[2];

        ll tx = (a + b)*2;
        ll ty = b*2+c;
        if (tx >ty) swap(tx, ty);

        if (tx <= x && ty <= y) ok = 1;

        tx = a+c;
        ty = b*3+a+c;

        if (tx <= x && ty <= y) ok = 1;

        if (ok){
            cout <<"Yes";
            return 0;
        }

    }while(next_permutation(A.begin(), A.end()));

    cout <<"No";
}
