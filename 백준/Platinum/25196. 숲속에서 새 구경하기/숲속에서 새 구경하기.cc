#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll Av, As, Ae, Bv, Bs, Be, Cv, Cs, Ce;
    cin >> Av >> As >> Ae >> Bv >> Bs >> Be >> Cv >> Cs >> Ce;
    
    if (Av < Cv) swap(Av, Cv), swap(As, Cs), swap(Ae, Ce);
    if (Bv < Cv) swap(Bv, Cv), swap(Bs, Cs), swap(Be, Ce);
    
    ll sz = Av*Bv; // < 4000000
    
    vector<ll> AB(sz);
    for (int i = 0; i < sz; i++){
        ll c = 0;
        ll v = i%Av;
        if (v >= As && v <= Ae) c++;
        v = i % Bv;
        if (v >= Bs && v <= Be) c++;
        
        AB[i] = (c == 2);
    }
    
    for (ll i = 1; i < sz;i ++) AB[i] += AB[i-1];
    
    vector<bool> visited(sz);
    ll curr = 0, cnt = sz;
    ll ans = -1;
    while(cnt--){
        
        if (visited[curr*Cv % sz]) break;
        visited[curr*Cv % sz];
        ll l = (curr*Cv + Cs)%sz;
        ll r = (curr*Cv + Ce) % sz;
        
        bool isin = 0;
        if (l <= r){
            ll cnt = AB[r];
            if (l > 0) cnt -= AB[l-1];
            isin = cnt > 0;
        }
        else{
            ll cnt = AB[sz-1] - AB[l-1] + AB[r];
            isin = cnt > 0;
        }
        
        if (isin) {
            ans = curr;
            break;
        }
        
        curr++;
    }
    
    if (ans == -1) {
        cout << -1;
        return 0;
    }
    int ix = 0;
    while(1){
        curr = (ans*Cv + Cs + ix) % sz;
        if (curr == 0){
            if (AB[curr]){
                cout << ans*Cv + Cs + ix;
                return 0;
            }
        }
        else if(AB[curr] - AB[curr-1] > 0){
            cout << ans*Cv + Cs + ix;
            return 0;
        }
        ix++;
    }
    
    
}
