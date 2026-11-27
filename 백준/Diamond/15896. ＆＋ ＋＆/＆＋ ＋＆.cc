#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


const int mod = 1999;

void solve(){
    
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    ll ans1 = 0, ans2 = 0;

    vector<ll> cnt1(30), cnt2(30);
    for(auto f : A){
        for(int j = 0; j < 30; j++) if (f & (1 << j)) cnt1[j]++;
    }
    for(auto f : B){
        for(int j = 0; j < 30; j++) if (f & (1 << j)) cnt2[j]++;
    }

    for(int i = 0; i < 30 ; i++){
        ll val = 1 << i;
        ll cnt = cnt1[i] * cnt2[i] % mod;
        ans1 += val * cnt % mod;
        ans1 %= mod;
    }

    for(int i = 29; i >= 0; i--){
        vector<int> A0(3, -1), A1(3, -1), B0(3, -1), B1(3, -1);
        
        for(auto f : A){
            int val = f % (1 << i);
            if (f & (1 << i)){
                if (A1[0] == -1) A1 = {val, val, val};
                else{
                    A1[1] = val;
                    for(int a = 0; a < 3; a++){
                        for(int b =a +1; b < 3; b++){
                            if (A1[a] > A1[b]) swap(A1[a], A1[b]);
                        }
                    }
                }
            }
            else{
                if (A0[0] == -1) A0 = {val, val, val};
                else{
                    A0[1] = val;
                    for(int a = 0; a < 3; a++){
                        for(int b =a +1; b < 3; b++){
                            if (A0[a] > A0[b]) swap(A0[a], A0[b]);
                        }
                    }
                }
            }
        }

        for(auto f : B){
            int val = f % (1 << i);
            if (f & (1 << i)){
                if (B1[0] == -1) B1 = {val, val, val};
                else{
                    B1[1] = val;
                    for(int a = 0; a < 3; a++){
                        for(int b =a +1; b < 3; b++){
                            if (B1[a] > B1[b]) swap(B1[a], B1[b]);
                        }
                    }
                }
            }
            else{
                if (B0[0] == -1) B0 = {val, val, val};
                else{
                    B0[1] = val;
                    for(int a = 0; a < 3; a++){
                        for(int b =a +1; b < 3; b++){
                            if (B0[a] > B0[b]) swap(B0[a], B0[b]);
                        }
                    }
                }
            }
        }
        
        int val = 1 << i;
        bool ok = 1;
        if (A1[2] != -1 && B0[2] != -1 && A1[2] + B0[2] >= val) ok = 0;
        if (B1[2] != -1 && A0[2] != -1 && B1[2] + A0[2] >= val) ok = 0;
        if (A1[0] != -1 && B1[0] != -1 && A1[0] + B1[0] < val) ok = 0;
        if (A0[0] != -1 && B0[0] != -1 && A0[0] + B0[0] < val) ok = 0;

        // cout << "REs: " <<  i<< '\n';
        // for(auto f : {A0, A1, B0, B1}){
        //     cout << f[0] << ' ' << f[2] << '\n';
        // }
        // cout << ok << '\n';
        if (ok) ans2 += val;
    }

    cout << ans1 << ' '<< ans2 << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
