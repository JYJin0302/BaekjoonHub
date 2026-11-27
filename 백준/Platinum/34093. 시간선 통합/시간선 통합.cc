#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second


void solve(){
    
    int n, t, m, M;
    cin >> n >> t>> m >> M;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    int ix = 0;
    while(ix < n && A[ix] != t) ix++;

    for(auto& f : A) {
        if(f > t) f = 1;
        else f = 0;
    }

    int cntL = n - t;
    int cntS = t - 1;

    if (cntL <= m && cntS <= M){
        cout << "yes\n";
        string s;
        vector<int> ans;
        for(int i = ix - 1; i >= 0; i--){
            if (A[i]) s += 'm';
            else s += 'M';
            ans.push_back(i + 1);
        }
        for(int i = ix+1;i < n; i++){
            if (A[i]) s += 'm';
            else s += 'M';
            ans.push_back(1);
        }

        cout << s<< '\n';
        for(auto f : ans) cout << f << ' ';
        cout << '\n';
        return;
    }
    
    bool swp = 0;
    if (cntL > m){
        swp = 1;
        for(auto &f : A) f = 1 - f;
        swap(cntL, cntS);
        swap(m, M);
    }
    
    // cntS > M
    string ansS;
    vector<int> ans;

    int lenL = ix;
    for(int i = ix-1; i >= 0; i--){
        if(A[i]){
            ans.push_back(i+1);
            ansS += 'm';
            m--;
            lenL--;
        }
    }
    
    int tL = lenL;
    int tR = 0;
    for(int i = ix+1; i < n; i++){
        if (A[i]){
            ans.push_back(lenL + 1);
            ansS += 'm';
            m--;
        }
        else lenL++, tR++;
    }

  //  cout << tL << ' ' << tR << '\n';

    if(m + M < tL + tR){
        cout << "no\n";
        return;
    }

    int nd = 0;
    if(tL) nd++;
    if (tR) nd++;
    if (M < nd){
        cout << "no\n";
        return;
    }

    for(int i = 0; i < tL; i++){
        ans.push_back(1);
        if(i == tL-1 || m == 0){
            ansS += 'M';
            M--;
        }
        else {
            ansS += 'm';
            m--;
        }
    }

    for(int i = 0; i < tR; i++){
        if(i == tR - 1) ans.push_back(1);
        else ans.push_back(2);
        if(i == tR-1 || m == 0){
            ansS += 'M';
            M--;
        }
        else {
            ansS += 'm';
            m--;
        }
    }

    if (swp){
        for(auto& f : ansS){
            f = ('m' + 'M' - f);
        }
    }

    if (m < 0 || M < 0){
        cout << "no\n";
        return;
    }

    cout << "yes\n";
    cout << ansS << '\n';
    for(auto f : ans) cout << f<< ' ';
    cout << '\n';


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
