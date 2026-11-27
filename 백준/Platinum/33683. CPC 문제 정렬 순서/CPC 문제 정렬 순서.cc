#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> A(n);
    for(int i =0 ; i < n; i++){
        cin >> A[i].x.x >> A[i].x.y;
        A[i].y = i;
    }
    sort(all(A));

    int ix = 0;
    int curVal = 0;
    set<pair<int, int>> st;

    vector<int> ansGrp(n), ansVal(n);
    int grp = 0;
    for(int i = 0; i < n; i++){
        if (st.empty() && ix < n) curVal = A[ix].x.x;
        while(ix < n && A[ix].x.x <= curVal){
            st.insert(mp(A[ix].x.y, A[ix].y));
            ix++;
        }

        auto[a,b] = *st.begin();
        st.erase(st.begin());

        if (a < curVal || grp == m){
            ansGrp[b] = grp;
            ansVal[b] = a;
        }
        else{
            ansGrp[b] = ++grp;
            ansVal[b] = curVal++;
        }
    }

    if (grp != m){
        cout << -1 << '\n';
    }
    else{
        for(int i = 0; i < n ; i++){
            cout << ansVal[i] << ' ' << ansGrp[i] << '\n';
        }
    }
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