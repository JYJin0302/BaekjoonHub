#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<int, int>> rec[202020];

int fw[404040];
void update(int ix, int val){
    while(ix <= 400000){
        fw[ix] += val;
        ix +=ix & -ix;
    }
}

int getS(int ix){
    int res= 0;
    while(ix){
        res += fw[ix];
        ix-= ix & -ix;
    }
    return res;
}

void solve(){
    
    int n, m, k;
    cin >> n >> m >>k;

    vector<int> num = {0};
    vector<pair<int, int>>  A(n);
    for(auto & i : A) {
        cin >> i.x >> i.y;
        num.push_back(i.x);
        num.push_back(i.y + 1);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());


    for(auto&[a,b]:A){
        a = lower_bound(all(num), a) - num.begin();
        b = lower_bound(all(num), b + 1) - num.begin() - 1;

        //cout << a << ' ' << b << '\n';
    }


    vector<int> ans(m+1);

    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        b--, c--;
        int ai = lower_bound(all(num), a + 1) - num.begin() - 1;
        rec[c].push_back(mp(ai, i));
        if (b){
            rec[b-1].push_back(mp(ai, -i));
        }
    }

    int tn = (int)num.size();
    for(int i = 0; i < n; i++){
        auto[a,b] = A[i];

        update(a, 1);
        update(b+1, -1);

        //cout << "Qur: " << i << "\n";
        for(auto[c, d] : rec[i]){
            //cout << c << ' '<< d << ' ' << getS(c) << '\n';
            if(d > 0){
                ans[d] += getS(c);
            }
            else ans[-d] -= getS(c);
        }
    }

    //cout << "Asns: ";
    for(int i = 1; i <= m; i++)cout << ans[i] << '\n';

    
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
