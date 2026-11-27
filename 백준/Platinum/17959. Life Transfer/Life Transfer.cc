#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll age1, age2, cost1, cost2;
    cin >> age1 >> cost1 >> age2 >> cost2;

    ll t, d;
    cin >> t >> d;

    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A.rbegin(), A.rend()-1);

    ll bonusAge = 0, needAge = 0;
    vector<ll> need(n + 1);
    for(int i = 1; i <= n; i++){
        
        if (A[i] < age2) {
            if (age2 - A[i] > d) need[i] = 1e9;
            else need[i] = age2 - A[i];
            needAge += need[i];
        }
        else {
            bonusAge += min(d, A[i] - age2);
            need[i] = min(d, A[i] - age2);
        }
    }

    ll ans = 1e15;
    ll l = 1, r = n;
    while (l <= n) {

        //cout << "Curr: " << l << ' ' << r << ' ' << bonusAge << ' ' << needAge << '\n';

        if (l > r) {
            ll tans = needAge * t + (l-1) * cost1;
            if(bonusAge >= needAge) ans = min(ans, tans);
            break;
        }

        if (bonusAge >= needAge) {
            ll tans = needAge * t + (l-1) * cost1 + (r-l+1) * cost2;
            ans = min(ans, tans);
        }

        if (age1 - A[l] > d) break;

        if (A[l] >= age2) bonusAge -= min(d, A[l] - age2);
        else needAge -= need[l];

        if (A[l] < age1) needAge += age1 - A[l];
        else bonusAge += min(d, A[l] - age1);
        l++;


        ll nr = max(l-1, r - k + 1);

        for (int i = r; i > nr; i--) {

            if (A[i] >= age2) bonusAge -= min(d, A[i] - age2);
            else needAge -= need[i];

            bonusAge += min(d, A[i] - 1);
        }
        r -= k - 1;
    }

    if (ans == 1e15)  ans = -1;
    cout << ans;
    
}
