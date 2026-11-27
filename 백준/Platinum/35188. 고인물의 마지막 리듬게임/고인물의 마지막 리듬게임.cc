#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ld eps = 1e-9;

bool okL[505050];
bool okR[505050];
void solve(){
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<ll, ll>> A(m);
    for(int i = 0;i < n; i++){
        int t, a ,b;
        cin >> t>> a>> b;
        A[t].x += a;
        A[t].y += b;
    }

    ld L = 0, R = 1, ans = 0;
    while(R- L > eps){
        ld md = (L+R)/2;


        deque<pair<int, ld>> dq;
        dq.push_front(mp(-1, 0));
        ld tot = 0;
        for(int i =0; i < m; i++){
            ld val = A[i].x - A[i].y * md;
            tot += val;

            while(!dq.empty() && dq.front().x < i - k) dq.pop_front();

            assert(!dq.empty());
            ld res = tot - dq.front().y;
            okL[i] = res >= eps;
            

            while(!dq.empty() && dq.back().y > tot){
                dq.pop_back();
            }
            dq.push_back(mp(i, tot));
        }

        while(!dq.empty()) dq.pop_back();

        // okR
        dq.push_front(mp(m, 0));
        tot = 0;
        for(int i = m-1; i>= 0; i--){
            ld val = A[i].x - A[i].y * md;
            tot += val;

            while(!dq.empty() && dq.front().x > i + k) dq.pop_front();

            assert(!dq.empty());
            ld res = tot - dq.front().y;
            okR[i] = res >= eps;

            while(!dq.empty() && dq.back().y > tot){
                dq.pop_back();
            }
            dq.push_back(mp(i, tot));
        }

        // valid check
        bool ok = 1;
        for(int i= 0 ; i <= m;i++){
            if(i == 0){
                ok &= okR[i];
            }
            else if (i == m){
                ok &= okL[i-1];
            }
            else{
                ok &= okL[i-1] || okR[i];
            }
        }

        if (ok){
            ans = max(ans, md);
            L = md;
        }
        else R = md;
    }

    cout << fixed << setprecision(16);
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