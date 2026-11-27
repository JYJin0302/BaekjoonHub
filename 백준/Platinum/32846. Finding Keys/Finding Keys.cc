#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define pi pair<int, int>

int SA[202020];
int ord[202020];
int LCP[202020];

void get_sa(const string& A){
    string a = A;
    int n = a.size();
    
    vector<pair<int, int>> tmp;
    for(int i =0 ;i < n;i++) tmp.push_back(mp(a[i] - '0', i));
    sort(all(tmp));
    for(int i =0 ;i < n; i++){
        SA[i] = tmp[i].y;
    }
    ord[SA[0]] = 0;
    for(int i =1 ;i < n; i++){
        if(tmp[i].x == tmp[i-1].x) ord[SA[i]] = ord[SA[i-1]];
        else ord[SA[i]] = ord[SA[i-1]] + 1;
    }

    for(int d = 1; ; d <<= 1){
        bool fin = 0;
        if(d >= n){
            fin =1 ;
        }
        vector<array<int, 3>> tmp(n), tmp2(n);
        for(int i =0 ; i< n;i++){
            if (fin) tmp[i] = {ord[SA[i]], i+1, SA[i]};
            else tmp[i] = {ord[(SA[i] + n - d)%n], ord[SA[i]], (SA[i] + n - d) % n};
        }
        vector<int> cnt(n), pos(n);
        for(int i =0 ; i < n; i++){
            cnt[tmp[i][0]]++;
        }

        for(int i =1;i < n; i++){
            pos[i] = cnt[i-1] + pos[i-1];
            if (pos[i] == n) break;
        }

        for(int i = 0; i < n; i++){
            int ix = pos[tmp[i][0]]++;
            tmp2[ix] = tmp[i];
            SA[ix] = tmp[i][2];
        }

        ord[SA[0]] = 0;
        for(int i =1 ; i < n; i++){
            if (tmp2[i][0] == tmp2[i-1][0] && tmp2[i][1] == tmp2[i-1][1]) ord[SA[i]] = ord[SA[i-1]];
            else ord[SA[i]] = ord[SA[i-1]] + 1;
        }

        if (fin || ord[SA[n-1]] == n-1) break;
    }

}
void getLCP(const string& A){
    
    string a = A;
    int N = a.size();

    int d = 0;
    for(int i =0 ;i < N; i++){
        int x = ord[i];
        if (x){
            int pv = SA[x-1];
            while(A[(i+d) % N] == A[(pv+d)%N] && d < N) d++;
        }
        else d = 0;
        LCP[x] = d;
        d = max(d-1, 0);
    }

}


void solve(){

    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    string s;
    for(int i = 0; i < n; i++){
        int ni = i+1;
        if (ni == n) ni = 0;
        if (A[i] < A[ni]) s += '1';
        else s += '0';
    }
    //cout << s<< '\n';

    get_sa(s);
    getLCP(s);

    // for(int i = 0; i < n; i++){
    //     cout << SA[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << ord[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << LCP[i] << ' ';
    // }
    // cout << '\n';

    for(int i = 0 ; i< n; i++){
        int pos = ord[i];
        int val = LCP[pos];
        if (pos != n-1) val = max(val, LCP[pos+1]);

        if (val == n) cout << -1 << '\n';
        else cout << val + 1 << '\n';
    }
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
