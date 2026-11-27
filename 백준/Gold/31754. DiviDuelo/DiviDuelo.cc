#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

void solve(){
    
    ll n;
    cin >> n;
    if (n == 1){
        cout << "N\n";
        return;
    }

    ll tn = n;
    vector<pair<ll, ll>> A;

    for(ll i = 2; i*i <= n; i++){
        if (n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            A.push_back(mp(i, cnt));
        }
    }
    if (n != 1) A.push_back(mp(n ,1));

    if (A.size() >= 3){
        cout << "N\n";
        return;
    }

    if (A.size() == 1){
        if (A[0].second & 1) cout << "Y\n";
        else cout << "N\n";
        return;
    }

    if (A[0].first * A[1].first == tn) cout << "Y\n";
    else cout << "N\n";


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}