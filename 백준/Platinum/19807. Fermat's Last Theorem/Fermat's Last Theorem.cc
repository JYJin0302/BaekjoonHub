#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool cmp(int a, int b, int c, int n){
    // a^n + b^n > c^n ??
    if (a > b) swap(a, b);
    if (b >= c) return 1;

    long double p1 = 1.0 * a / b;
    long double p2 = 1.0 * c / b;

    long double r1 = 1, r2 = 1;
    
    while(n){
        if (n & 1){
            r1 *= p1;
            r2 *= p2;
        }
        p1 = p1 * p1;
        p2 = p2 * p2;
        n >>= 1;
    }
    return r1 + 1 > r2;

}

void solve(ll l){

    ll st = 3;
    array<ll, 4> state;

    while(st * st * st * (st-2) < l){
        st++;
    }

    ll tmpL = l - (st - 1)* (st - 1) *(st - 1)* (st - 3);

    state = {1, 1, 1, 3};

    bool mxUsed = 0;
    for(int i =0 ; i < 3; i++){
        for(int j = 1; j <= st; j++){
            // cnt
            ll cc = st - 2;
            for(int j = 0; j < 2- i; j++){
                cc *= st;
            }
            if(!mxUsed && j != st){
                ll c2 = st - 3;
                for(int j = 0; j < 2 - i; j++){
                    c2 *= st - 1;
                }
                cc -= c2;
            }
            if (cc < tmpL){
                tmpL -= cc;
            }
            else{
                state[i] = j;
                if(j == st) mxUsed = 1;
                break;
            }
        }
    }

    if (!mxUsed){
        state[3] = st;
    }
    else{
        state[3] = 3 + tmpL - 1;
    }


    int a= state[0];
    int b = state[1];
    int c= state[2];
    int n =state[3];


    if (cmp(a, b, c, n)){
        cout << a << '^' << n << '+' << b << '^' << n << ">" << c << "^" << n << '\n';
    }
    else{
        cout << a << '^' << n << '+' << b << '^' << n << "<" << c << "^" << n << '\n';
    }


    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;

    ll L, R;
    cin >> L >> R;
    for(ll i =  L; i <= R; i++){
        solve(i);
    }
    return 0;
}

