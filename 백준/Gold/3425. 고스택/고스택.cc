#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

#define ERR {cout << "ERROR\n"; return;}
const ll LIM = 1e9;

vector<pair<string, ll>> inst;
void getInst(){
    inst.clear();
    string s;
    ll x;
    while(1){
        cin >> s;
        if (s[0] == 'Q') exit(0);
        if (s[0] == 'E') return;

        if (s[0] == 'N') {
            cin >> x;
            inst.push_back(mp(s, x));
        }
        else inst.push_back(mp(s, 0));
    }
}

void simul(ll x){
    stack<ll> st;
    st.push(x);
    for(auto[a,b] : inst){
        int sn = st.size();

        if (a == "NUM"){
            st.push(b);
        }
        else if (a == "POP"){
            if (sn == 0) ERR;
            st.pop();
        }
        else if (a == "INV"){
            if (sn == 0) ERR;
            ll v = st.top(); st.pop();
            st.push(-v);
        }
        else if (a == "DUP"){
            if (sn == 0) ERR;
            st.push(st.top());
        }
        else if (a == "SWP"){
            if (sn < 2) ERR;
            ll v1 = st.top(); st.pop();
            ll v2 = st.top(); st.pop();
            st.push(v1); st.push(v2);
        }
        else if (a == "ADD"){
            if(sn < 2) ERR;
            ll v1 = st.top(); st.pop();
            ll v2 = st.top(); st.pop();
            if (abs(v1 + v2) > LIM) ERR;
            st.push(v1 + v2);
        }
        else if ( a == "SUB"){
            if(sn < 2) ERR;
            ll v1 = st.top(); st.pop();
            ll v2 = st.top(); st.pop();
            if (abs(v2 - v1) > LIM) ERR;
            st.push(v2 - v1);
        }
        else if (a == "MUL"){
            if(sn < 2) ERR;
            ll v1 = st.top(); st.pop();
            ll v2 = st.top(); st.pop();
            if (abs(v1 * v2) > LIM) ERR;
            st.push(v1 * v2);
        }
        else if (a == "DIV"){
            if(sn < 2) ERR;
            ll v1 = st.top(); st.pop();
            ll v2 = st.top(); st.pop();
            if (v1 == 0) ERR;
            bool neg = (v1 < 0) ^ (v2 < 0);
            ll val = abs(v2) / abs(v1);
            if (neg) val *= -1;
            st.push(val);
        }
        else if (a == "MOD"){
            if(sn < 2) ERR;
            ll v1 = st.top(); st.pop();
            ll v2 = st.top(); st.pop();
            if (v1 == 0) ERR;
            bool neg = (v2 < 0);
            ll val = abs(v2) % abs(v1);
            if (neg) val *= -1;
            st.push(val);
        }
    }

    int sn = st.size();
    if (sn != 1) ERR;
    cout << st.top() << '\n';
}

void solve(){

    while(1){
        getInst();

        // for(auto[a,b] : inst) cout << a<< ' ' << b << " || ";
        // cout << '\n';

        int n;
        cin >> n;
        for(int i = 0; i < n ;i++){
            ll x;
            cin >> x;

            simul(x);
        }
        cout << '\n';
    }   

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
