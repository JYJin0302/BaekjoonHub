#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
int n = sz(a), L = 31- __builtin_clz(n);
static vector<complex<long double>> R(2, 1);
static vector<C> rt(2, 1); // (^ 10% faster if double)
for (static int k = 2; k < n; k *= 2) {
R.resize(n); rt.resize(n);
auto x = polar(1.0L, acos(-1.0L) / k);
rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
}
vi rev(n);
rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
for (int k = 1; k < n; k *= 2)
for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled) /// include-line
auto x = (double *)&rt[j+k], y = (double
*)&a[i+j+k];
/// exclude-line
C z(x[0]*y[0]- x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
/// exclude-line
a[i + j + k] = a[i + j]- z;
a[i + j] += z;
}
}
vd conv(const vd& a, const vd& b) {
if (a.empty() || b.empty()) return {};
vd res(sz(a) + sz(b)- 1);
int L = 32- __builtin_clz(sz(res)), n = 1 << L;
vector<C> in(n), out(n);
copy(all(a), begin(in));
rep(i,0,sz(b)) in[i].imag(b[i]);
fft(in);
for (C& x : in) x *= x;
rep(i,0,n) out[i] = in[-i & (n- 1)]- conj(in[i]);
fft(out);
rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
return res;
}


void solve(){
        
    vd tmp(1000000), tmp2(1000000);

    string s1, s2;
    cin >> s1 >> s2;


    if (s1[0] == '0' || s2[0] == '0'){
        cout << 0 << '\n';
        return;
    }

    reverse(all(s1));
    reverse(all(s2));
    for(int i = 0; i < (int)s1.size(); i++){
        tmp[i] = s1[i] - '0';
    }
    for(int i = 0; i < (int)s2.size(); i++){
        tmp2[i] = s2[i] - '0';
    }

    vd res = conv(tmp, tmp2);

    string ans;
    ll pre = 0;
    for(int i =0 ; i < (int)res.size(); i++){
        pre += (ll)(res[i] + 0.5);
        ans += char('0' + pre % 10);
        pre /= 10;
    }
    while(pre){
        ans += char('0' + pre % 10);
        pre /= 10;
    }
    reverse(all(ans));

    int ix = 0;
    while(ix < (int)ans.size() && ans[ix] == '0') ix++;
    while(ix < (int)ans.size()) cout << ans[ix++];
    cout << '\n';
    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}