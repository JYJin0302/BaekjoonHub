#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
ll ret = a * b- M * ull(1.L / M * a * b);
return ret + M * (ret < 0)- M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
ull ans = 1;
for (; e; b = modmul(b, b, mod), e /= 2)
if (e & 1) ans = modmul(ans, b, mod);
return ans;
}
bool isPrime(ull n) {
if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
ull A[] = {2, 325, 9375, 28178, 450775, 9780504,
1795265022},
s = __builtin_ctzll(n-1), d = n >> s;
for (ull a : A) { // ^ count trailing zeroes
ull p = modpow(a%n, d, n), i = s;
while (p != 1 && p != n- 1 && a % n && i--)
p = modmul(p, p, n);
if (p != n-1 && i != s) return 0;
}
return 1;
}

ull pollard(ull n) {
auto f = [n](ull x) { return modmul(x, x, n) + 1; };
ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
while (t++ % 40 || gcd(prd, n) == 1) {
if (x == y) x = ++i, y = f(x);
if ((q = modmul(prd, max(x,y)- min(x,y), n))) prd =
q;
x = f(x), y = f(f(y));
}
return gcd(prd, n);
}
vector<ull> factor(ull n) {
if (n == 1) return {};
if (isPrime(n)) return {n};
ull x = pollard(n);
auto l = factor(x), r = factor(n / x);
l.insert(l.end(), r.begin(), r.end());
return l;
}

void solve(){
    
    ll x;
    cin >> x;

    vector<ull> A = factor(x);
    
    sort(all(A));

    vector<int> nA;
    int cnt= 1;
    for(int i =1; i < (int)A.size(); i++){
        if (A[i] == A[i-1]) cnt++;
        else{
            nA.push_back(cnt);
            cnt =1;
        }
    }
    nA.push_back(cnt);
    sort(all(nA));
    
    int tot = 0;
    for(auto f: nA) tot += f;
    if (nA.back() * 2 > tot){
        cout << "yyyy7089\n";
        return;
    }

    if (tot & 1) cout << "yyyy7089\n";
    else cout << "toycartoon\n";
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}