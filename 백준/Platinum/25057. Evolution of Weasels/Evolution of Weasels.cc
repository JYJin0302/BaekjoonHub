#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pii;
#define mp make_pair


void solve(){

    string u, v;
    cin >>u >>v;

    int ck = 0;

    vector<char> t1, t2;
    for(auto f : u){
        if (f == 'B') ck ^= 1;
        else {
            if (t1.empty() || t1.back() != f) t1.push_back(f);
            else if (!t1.empty() && t1.back() == f) t1.pop_back();
        }
    }
    for(auto f : v){
        if (f == 'B') ck ^= 1;
        else {
            if (t2.empty() || t2.back() != f) t2.push_back(f);
            else if (!t2.empty() && t2.back() == f) t2.pop_back();
        }
    }

    if (ck || t1 != t2) cout <<"NO\n";
    else cout <<"YES\n";

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);


    int t=1;
    cin >>t;
    while(t--){
        solve();
    }
}
