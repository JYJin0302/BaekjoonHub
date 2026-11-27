#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int encode[30];
void setV(int l, int r, int val, int dep = 5){
    if(l == r) {
        encode[l] = val << dep;

        return;
    }

    int md = (l+r)>>1;
    setV(l, md, val*2, dep - 1);
    setV(md+1, r, val*2+1, dep - 1);
}

int decode[77];

string bn(int x){
    string res;
    for(int i =0 ; i < 5; i++){
        res += char('0' + (x & 1));
        x >>= 1;
    }
    return res;
}

int ans[10101];
void solve(){
    
    setV(0, 25, 0);
    for(int i = 0; i < 26; i++){
        decode[encode[i]] = i;
    }


    cout << "? ";
    for(int j = 0; j < 26; j++) cout << char('a' + j);
    cout << endl;

    int k;
    cin >> k;
    int len = k;
    while(k--){
        int x;
        cin >> x;
    }

    for(int i = 0; i < 5; i++){
        string res;
        for(int j = 0; j < 26; j++){
            if(encode[j] & (1 << i)) res += char('a'+ j);
        }
        cout << "? " << res << endl;

        int k;
        cin >> k;
        vector<int> A(k);
        for(auto& f : A) cin >> f;
        for(auto f : A) ans[f] += 1 << i;
    }

    cout << "! ";
    for(int i = 1; i <= len ;i++) cout << char('a' + decode[ans[i]]);
    cout << endl;
    
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}