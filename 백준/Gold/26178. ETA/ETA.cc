#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    string s;
    cin >> s;

    ll b = 0, a = 0;
    
    int ix = 0;
    while(ix < (int)s.size()){
        char c = s[ix];
        if(c == '/'){
            ix++;
            break;
        }
        b = b * 10 + (c - '0');
        ix++;
    }
    while(ix < (int)s.size()){
        char c = s[ix];

        a = a * 10 + (c - '0');
        ix++;
    }

    ll g = gcd(a, b);
    a /= g, b /= g;

    ll v = 2 * b + a + (a*a - 1);
    v /= a*a;

    if (b < a-1){
        cout << "impossible\n";
        return;
    }

    if(b == a-1){
        cout << a<< ' ' << a-1 << '\n';
        for(int i = 2; i <= a; i++) cout << 1<< ' ' << i << '\n';
        return;
    }

    b *= v;
    a *= v;

    vector<int> ans(a-1);

    ll tot = 0;
    
    for(int i =0 ;i < a-1; i++){
        if(tot + a-1-i <= b){
            tot += a-1-i;
            ans[i]++;
        }
    }

    cout << a << ' ' << a-1 << '\n';
    vector<int> rec(a+1);
    rec[1] = 1;
    for(int i = 0; i < a-1; i++){
        if (i) ans[i] += ans[i-1];
        cout << rec[ans[i]] << ' ' << i+2 << '\n';
        rec[ans[i]+1] = i+ 2;
    }

    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}

