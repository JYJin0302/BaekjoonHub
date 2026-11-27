#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}


void solve(int n){
    
    ll t;
    int s;
    cin >> t >> s;
    vector<int> b(s);
    for(auto& f : b) cin >> f;

    if (s == 1){
        if (t % b[0] == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }
    if (s == 2){
        int g =gcd(b[0], b[1]);
        if (t % g != 0){
            cout << 0 << '\n';
            return;
        }

        int minX = -1, maxX = -1;
        for(int i = 0; i < 16; i++){
            int val = t - i * b[0];
            if (val >= 0 && val % b[1] == 0){
                minX = i;
                break;
            }
        }
        for(int i = 0; i < 16; i++){
            int val = t - i * b[1];
            if (val >= 0 && val % b[0] == 0){
                maxX = val / b[0];
                break;
            }
        }

        int step = b[1] / g;
        if (minX == -1 || maxX == -1) cout << 0 << '\n';
        else cout << (maxX - minX) / step + 1 << '\n';
        return;
    }

    vector<int> sol(256); // ax + by = k => f(k) 의 값 : sol[k]
    int g= gcd(b[0], b[1]);
    int R = b[0] * b[1] / g;
    for(int i = 0; i < R; i++){
        if (i % g != 0) sol[i] = 0;
        else{
            int ti = 0;
            while(ti <= i){
                int val = i - ti;
                if (val % b[1] == 0) sol[i]++;
                ti += b[0];
            }
        }
    }
    
    int minT = t % b[2];
    int maxT = t;
    // step : b[2]

    vector<int> sol2(256);
    
    int cnt = 0;
    for(int i = 0 ; i < R; i++){
        int val = minT + b[2] * i;
        if (val % g != 0){
            continue;
        }
        cnt++;
        sol2[i] = sol[val % R] + val / R;
    }

    // 각 R사이클마다 b[2]만큼 ++

    ll base = 0;
    for(int i = 0; i < R; i++) base += sol2[i];
    
    ll ans = 0;
    ll D = (maxT - minT) / b[2] + 1;

    ll d2 = D / R;
    // d2 길이의 배열: base, base + cnt*b[2], base + cnt*b[2] * 2, ...
    if (d2){
        ans += (base + base + cnt * b[2] * (d2 - 1)) * d2 / 2;
    }

    //cout << "Mid: " << ans << endl;
    ll tVal = minT + b[2] * (d2 * R);
    while(tVal <= maxT){
        if (tVal % g == 0){
            ans += sol[tVal % R] + tVal / R;
        }
        tVal += b[2];
    }

    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve(t);
    }

    return 0;
}