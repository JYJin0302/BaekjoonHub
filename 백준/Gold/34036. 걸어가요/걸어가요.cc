#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    if(a == 0) return b;
    return gcd(b%a, a);
}


void solve(){

    int n;
    cin >> n;
    
    vector<pair<ll, ll>> A(n);
    for(auto&[a,b]: A) cin >> a>> b;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if (abs(A[i].x - A[j].x) % gcd(A[i].y, A[j].y) == 0) {}
            else{
                cout << -1 << '\n';
                return;
            }
        }
    }

    for(int i = 1; i < n; i++){
        auto[a,b] = A[i-1];
        auto[c, d] = A[i];

        ll newA = b / gcd(b, d) * d;
        ll newB = -1;

        // a + bx == c + dy
        for(ll j = 0; j < newA / b; j++){
            ll valL = a + b * j - c;
            if (valL < 0){
                valL %= newA;
                if (valL < 0) valL += newA;
            }
            if (valL % d == 0){
                if (newB == -1 || newB > valL + c){
                    newB = valL + c;
                }
            }
        }

        assert(newB != -1);
        A[i] = mp(newB, newA);
    }

    cout << A[n-1].x << '\n';

    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}