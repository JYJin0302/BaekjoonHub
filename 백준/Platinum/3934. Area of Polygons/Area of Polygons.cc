#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int off = 2010;
vector<double> rec[4040], rec2[4040];


void solve(int n){
    
    vector<pair<int, int>> A(n);
    for(int i =0 ; i<n; i++){
        int a, b;
        cin >> a>> b;
        A[i] = mp(a, b);
    }

    // for(auto[a,b]: A) cout << "(" << a << ' '<< b << ") ";
    // cout << '\n';


    for(int i =0; i < n; i++){
        int ni = (i+1)% n;
        auto[x1, y1] = A[i];
        auto[x2,y2] = A[ni];
        if (y1 == y2) continue;

       // cout << "Cal :" << x1 << ' ' << y1 << " " << x2 << ' ' << y2 << endl;

        if (x1 == x2){
            int xx = x1;
            if (y1 > y2) swap(y1, y2);

            for(int yy = y1; yy < y2; yy++){
                rec[yy + off].push_back(xx);
                rec2[yy + off].push_back(xx);
            }
        }
        else{
            int dx = x2 - x1;
            int dy = y2 - y1;
            int g = gcd(abs(dx), abs(dy));
            dx /= g, dy /= g;

            
            for(int j = 0; j < abs(y2-y1); j++){
                double xpos = x1 + (0.000001 + j) * dx / abs(dy);
                double xpos2 = x1 + (j + 1 - 0.000001) * dx / abs(dy);
                int yx = y1;
                if(dy < 0) {
                    yx -= j + 1;
                    rec[yx+off].push_back(xpos2);
                    rec2[yx+off].push_back(xpos);

                    //cout << "ADD: " << yx << ' ' << xpos2 << ' ' << xpos << '\n';
                }
                else {
                    yx += j;
                    rec[yx+off].push_back(xpos);
                    rec2[yx+off].push_back(xpos2);
                    //cout << "ADD: " << yx << ' '<< xpos << ' '<< xpos2 << '\n';
                }
            }

        }

    }
    
    int ans = 0;

    cout << fixed << setprecision(6);
    for(int i = 0; i <= 4020; i++){
        if (rec[i].empty()) continue;
        sort(all(rec[i]));
        sort(all(rec2[i]));

        // cout << "REcord: " << i - off << " | ";
        // for(auto f: rec[i]) cout << f<< ' ';
        // cout << endl;
        // cout << "REco 2: " << i - off << " | ";
        // for(auto f: rec2[i]) cout << f<< ' ';
        // cout << endl;

        vector<pair<int, int>> tmp;
        for(int j = 1; j < (int)rec[i].size(); j+= 2){
            double L = rec[i][j-1];
            double R = rec[i][j];

            double L2 = rec2[i][j-1];
            double R2 = rec2[i][j];

            L = min(L, L2);
            R = max(R, R2);

            int tL = floor(L);
            int tR = ceil(R) - 1;
            tmp.push_back(mp(tL, tR));
        }
        sort(all(tmp));

        auto[l, r] = tmp[0];
        for(int j=  1; j < (int)tmp.size(); j++){
            auto[a,b] = tmp[j];
            if (a > r) {
                ans += r - l + 1;
                l = a, r = b;
            }
            else r =max(r, b);
        }
        ans += r- l+ 1;

        rec[i].clear();
        rec2[i].clear();
    }
    
    cout << ans << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n){
        solve(n);
        cin >> n;
    }
    return 0;
}
