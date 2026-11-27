#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

string sx, sy;
bool cmp(pair<ll, ll> p1, pair<ll, ll> p2){
    if ((p1.x < 0) != (p2.x < 0)) return p1.x < p2.x;
    if (p1.x == 0 && p2.x == 0){
        return p1.y < p2.y;
    }
    return p1.x * p2.y - p1.y * p2.x > 0;
}

ll ccw(pair<ll, ll> p1, pair<ll, ll> p2, bool sgn = 1){
    ll res = p1.x * p2.y - p2.x * p1.y;
    if (sgn && res) res /= abs(res);
    return res;
}

void solve(){
    
    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for(auto& i : A) cin >> i.x >> i.y;

    ll totx = 0, toty = 0;
    for(auto[a,b]: A){
        totx += a;
        toty += b;
    }

    int g = gcd(abs(totx), n);
    sx = to_string(totx / g) + "/" + to_string(n / g);
    int g2 = gcd(abs(toty), n);
    sy = to_string(toty / g2) + "/" + to_string(n / g2);

    if((totx % n) || (toty % n)){
        for(auto&[a,b]: A){
            a = 2*a - totx / (n/2);
            b = 2*b - toty / (n/2);
        }
    }
    else{
        for(auto&[a,b]: A){
            a = a - totx / n;
            b = b - toty / n;
        }
    }
    

    vector<pair<ll, ll>> tmp = A;
    for(auto &[a,b] :tmp){
        ll g= gcd(abs(a), abs(b));
        a /= g, b/=g;
    }
    sort(all(tmp), cmp);
    tmp.erase(unique(all(tmp)), tmp.end());

    int tn = (int)tmp.size();
    for(int i = 0; i < tn; i++){
        auto[a,b] = tmp[i];
        auto[c,d] = tmp[(i+ 1)%tn];

        ll tx = a + c;
        ll ty = b + d;
        ll g = gcd(abs(tx), abs(ty));
        tmp.push_back(mp(tx / g, ty / g));
    }
    sort(all(tmp), cmp);
    tmp.erase(unique(all(tmp)), tmp.end());

    tn = (int)tmp.size();
    
    vector<int> cnt(tn+1);

    vector<int> fdx(n);
    for(int i =0 ;i < n; i++){
        fdx[i] = lower_bound(all(tmp), A[i], cmp) - tmp.begin();
        if (fdx[i] == tn) fdx[i] = tn - 1;
    }


    vector<vector<int>> rec(tn + 10);
   // cout << tn << '\n';

    for(int i = 0; i < n; i++){
        int p0 = fdx[(i + n-1)% n];
        int p1 = fdx[i];
        int p2 = fdx[(i+1)%n];
        if (p0 == p1) p0 = fdx[(i + n-2) % n];

        ll r1 = ccw(tmp[p1], tmp[p0]);
        ll r2 = ccw(tmp[p1], tmp[p2]);

        if (r1 * r2 < 0){
            cnt[p1]++;
            cnt[p1 + 1]--;
        }
        
        if (p1 == p2) continue;
        // cout << "Search i: "<< i << " => ";
        // cout << p1 << ' ' << p2 << '\n';

        if (p1 > p2)swap(p1, p2);

        if (p2 - p1 < tn/2){
            cnt[p1+1]++;
            rec[p1+1].push_back(i);
            cnt[p2]--;
            rec[p2].push_back(i);
        }
        else{
            cnt[0]++;
            rec[0].push_back(i);
            cnt[p1]--;
            rec[p1].push_back(i);
            cnt[p2+1]++;
            rec[p2+1].push_back(i);
        }
    }

    for(int i = 1; i < tn; i++){
        cnt[i] += cnt[i-1];
    }

    vector<int> only(tn + 10, -1);
    vector<vector<int>> search(tn + 10);
    for(int i =0 ;i < n; i++){
        search[fdx[i]].push_back(i);
    }


    set<int> st;
    for(int i =0 ; i< tn; i++){
        for(auto f: rec[i]){
            if (st.find(f) != st.end()) st.erase(st.find(f));
            else st.insert(f);
        }

        // cout << i << ' ' << cnt[i] << " || ";
        // for(auto f : st) cout << f<< ' ';
        // cout << endl;
        if (cnt[i] == 1 && st.size() == 1){
            //cout << "Setup : "<< i << ' ' << tmp[i].x << ' ' << tmp[i].y << endl;
            only[i] = *st.begin();
        }
    }
    
    for(int i = 0; i < tn; i++){
        if (cnt[i] == 1){

            // valid check
            //cout << "\nGO CHECK :" << i << endl;
            vector<pair<double, int>> tt;
            for(auto f : search[i]){
                
                //cout <<  "Cc: " << A[f].x << ' '<< A[f].y << " " << fdx[f] << '\n';
                ll D = A[f].x*A[f].x + A[f].y*A[f].y;
                int p1 = i;
                int p0 = fdx[(f+n-1)% n];
                int p2 = fdx[(f+1)%n];
                if (p0 == p1) p0 = fdx[(f+n-2)%n];
                if (p2 == p1) p2 = fdx[(f+2)%n];

                int type = 0;
                ll r1 = ccw(tmp[p1], tmp[p0]); 
                ll r2 = ccw(tmp[p1], tmp[p2]); 
                if (r1 * r2 > 0){
                    type = 0;
                }
                else type = 1;
                
                tt.push_back(mp(D, type));
                //cout << "tt add: " << f<< ' ' << D << " "<< type << endl;
            }
            

            if (only[i] != -1){
                int i1 = only[i];
                int i2 = (i1+1)% n;

                if (ccw(A[i1], A[i2]) > 0) {}
                else swap(i1, i2);

                // cout << "only: " << A[i1].x << ' ' << A[i1].y << " | " <<  A[i2].x << ' ' << A[i2].y << '\n';
                // cout << "Target dir :" << tmp[i].x << ' ' << tmp[i].y << '\n';

                double l = 0, r = 1;
                while(r-l > 1e-6){
                    double md = (l+r)/2;

                    auto p = mp(A[i1].x * md + (1-md)* A[i2].x, A[i1].y * md + (1-md) * A[i2].y);

                    auto res1 = tmp[i].x * p.y - p.x * tmp[i].y;
                    if (res1 >= 0){
                        l = md;
                    }
                    else r = md;
                }
                double md = (l+r)/2;
                auto p = mp(A[i1].x * md + (1-md)* A[i2].x, A[i1].y * md + (1-md) * A[i2].y);

                //cout << "Found point : " << p.x << ' '<< p.y << '\n';
                tt.push_back(mp(p.x*p.x +p.y*p.y, 1));
            }
            sort(all(tt));

            // cout << "TT result : ";
            // for(auto f : tt) cout << f.x << ' '<< f.y << " || ";
            // cout << '\n';
            if (tt[0].y != 1) continue;

            // found
            auto dx = tmp[i].x;
            auto dy = tmp[i].y;


            cout << sx << ' ' << sy << ' ';
            ll x1 = (totx / g) + (n / g) * dx, x2 = n / g;
            ll y1 = (toty / g2) + (n / g2) * dy, y2 = n / g2;            
            cout << x1 << '/' << x2 << ' ' << y1 << '/' << y2 << '\n';

            return;
        }
    }
    cout << "impossible\n";
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
