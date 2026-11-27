#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
#define mp make_pair


int gcd(int a, int b){
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a, a);
}
vector<pair<int, int>> S[101010];
vector<int> tS[101010];


void solve(){
    
    int n;
    cin >> n;

    vector<int> A(n+1);
    vector<ld> P(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    ll tot = 0;
    for(auto f : A) tot += f;
    for(int i = 1; i <= n; i++) P[i] = 1.0 * A[i] / tot;

    vector<pair<ll, ll>> G;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n / i; j++){
            if(gcd(i, j) == 1){
                G.push_back(mp(i, j));
            }
        }
    }

    for(auto&[a,b] : G){
        ll c = a*b;
        ll ta = a, tb = b, tc = a*b;
        while(tc <= n && ta <= n && tb <= n){
            if (tc == ta){
                tS[ta].push_back(tb);
            }
            else{
                S[ta].push_back(mp(tb, tc));
            }
            tc += c;
            ta += a;
            tb += b;
        }
    }


    vector<ld> dp(n+10);

    for(int i = n; i >= 1; i--){
        ld c = 0;
        ld a = 0;
        for(auto[a,b] : S[i]){
            c += (dp[b] + 1) * P[a];
        }

        for(auto f : tS[i]){
            a += P[f];
            c += P[f];
        }

        dp[i] = c / (1-a);
    }

    cout << setprecision(15);
    cout << dp[1];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}