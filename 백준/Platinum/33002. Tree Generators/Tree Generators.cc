#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int> pi;

int n;
const int mod = 998244353;
int L1[707070], R1[707070];
int L2[707070], R2[707070];

int tot = 0;
void setLen(string s, int L[], int R[]){

    int ord = 0;
    stack<pair<int, int>> st;

    for(auto f : s){
        if(f == '('){
            st.push(mp(-1, -1));
        }
        else if (f == ')'){
            pair<int, int> r = st.top(); st.pop();
            pair<int, int> l = st.top(); st.pop();
            st.pop();

            L[l.second] = l.second - l.first + 1;
            R[l.second] = r.second - r.first + 1;
            st.push(mp(l.first, r.second));
        }
        else{
            ++ord;
            st.push(mp(ord, ord));
        }
    }
    tot = ord;
}

void solve(){
    
    string s1, s2;
    cin >> s1 >> s2;

    n = s1.size();

    setLen(s1, L1, R1);
    setLen(s2, L2, R2);

    ll res = 1;

    for(int i = 1; i < tot; i++){
        ll lval = 0, rval = 0;
        lval = min(L1[i], L2[i]);
        rval = min(R1[i], R2[i]);

        (res *= lval * rval % mod) %= mod;
    }
    cout << res << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}