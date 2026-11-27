#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
int cnt[505050];
ll S[505050];
 
 
void solve(){
    
    for(int i = 2; i <= 500000; i++){
        if (cnt[i]) continue;
        for(int j = i; j <= 500000; j+= i){
            cnt[j]++;
            S[j] += i;
        }
    }
 
    int n, m;
    cin >> n >> m;
    vector<int> A(n+1);
    for(int i =1; i <= n; i++) cin >> A[i];
 
    vector<int> B(n+5);
    while(m--){
        int a, b;
        cin >> a>> b;
        B[a]++;
        B[b+1]--;
    }
 
    ld ans = 0;
    for(int i =1; i <= n;i ++){
        B[i] += B[i-1];
        if (B[i]){
            ans += 1.0 * S[A[i]] / cnt[A[i]];
        }
        else ans += A[i];
    }
    cout << setprecision(16);
    cout << ans << '\n';
 
 
 
}
 
 
 
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
