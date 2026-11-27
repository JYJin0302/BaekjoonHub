#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> getS(ll val){

    vector<ll> res;
    while(1){
        if (val < 10) {
            res.push_back(val);
            break;
        }
        string s = to_string(val);        
        string rs = s;
        int sn = rs.size();
        if (s[0] == '1'){
            rs = string(sn-1, '9');
        }
        else{
            rs[0] = (s[0] - 1);
            rs[sn-1] = rs[0];
            for(int i = 1; i < sn-1; i++) rs[i] = '9';
        }

        ll nval = stoll(rs);
        val -= nval;
        res.push_back(nval);

        if (val == 0) break;
    }

    return res;

}

void solve(){
    
    ll p, q;
    cin >> p >> q;

    string ans;
    bool rev = 0;
    if (p < q) {
        swap(p, q);
        rev = 1;
    }
    if (abs(p % 2) != abs(q % 2)){
        ans += "+11-12";
        p++;
        q -= 10;
    }

    ll D = (p - q) / 2;
    vector<ll> r1 = getS(D);
    for(auto f: r1){
        ans += '+';
        ans += to_string(f);
        ans += '-';
        ans += '0';
    }

    ll md = (p+q)/2;

    if (md < 0){
        string ts = to_string(-md);
        string res;
        int sn = ts.size();
        res = string(sn, '9');

        if (md <= -1000000000000000000){
            res = "2000000000000000002";
        }

        ans += '+';
        ans += '1';
        ans += '-';
        ans += res;
        ans += '-';
        ans += '1';

        ll ss = stoll(res);
        md += ss;
    }

    vector<ll> r2 = getS(md);
    for(auto f : r2){
        ans += '+';
        ans += to_string(f);
    }

    string rans = ans.substr(1);

    if (rev) reverse(rans.begin(), rans.end());
    cout << rans << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}