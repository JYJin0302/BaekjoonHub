#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int L[202020];
int R[202020];
ll S[202020];

int find(int n, int root[]){
    if(root[n] == n)return n;
    return root[n] = find(root[n], root);
}


void solve(){
    
    int n;
    cin >> n;
    vector<pair<ll, ll>> A(n + 1);
    for(int i = 1;i <= n; i++){
        cin >> A[i].x >> A[i].y;
    }

    for(int i = 1; i <= n;i++) {
        L[i] = R[i] = i;
        S[i] = A[i].y;
        if (A[i].x == 1) S[i] *= -1;
    }

    vector<pair<int, int>> ans;
    vector<array<ll, 3>> T1, T2;
    for(int i = 1; i <= n; i++){
        
        T1.push_back({A[i].x, A[i].y, i});
        if (T2.empty() || (T2.back()[0] < 0) != (A[i].x < 0)) T2.push_back({A[i].x, A[i].y, i});
        else T2.back()[1] += A[i].y;

        while(1){
            bool dif = 0;
            if(T1.size() >= 2){
                auto f2 = T1.back(); T1.pop_back();
                auto f1 = T1.back(); T1.pop_back();

                ll res = f1[0] * f1[1] + f2[0] * f2[1];

                if(res < 0){
                    dif = 1;
                    ans.push_back(mp(f1[2], i));
                    T1.push_back({-1, f1[1] + f2[1], f1[2]});
                }
                else{
                    T1.push_back(f1);
                    T1.push_back(f2);
                }
            }

            if (T1.size() >= 3){
                auto f3 = T1.back(); T1.pop_back();
                auto f2 = T1.back(); T1.pop_back();
                auto f1 = T1.back(); T1.pop_back();

                ll res = f1[0] * f1[1] + f2[0] * f2[1] + f3[0] * f3[1];
                if(res < 0){
                    dif = 1;
                    ans.push_back(mp(f1[2], i));
                    T1.push_back({-1, f1[1] + f2[1] + f3[1], f1[2]});
                }
                else{
                    T1.push_back(f1);
                    T1.push_back(f2);
                    T1.push_back(f3);
                }
            }

            if(!dif) break;
        }

        // cout << "STATE: \n";
        // cout << "T1 :" ;
        // for(auto f : T1) cout << "{ " << f[0] << ' ' << f[1] << ' ' << f[2] << "} ";
        // cout << '\n';
    }

    if (T1.size() == 1 && T1[0][0] == -1){
        cout << (int)ans.size() << '\n';
        for(auto[a,b] : ans) cout << a << ' ' << b << '\n';
    }
    else{
        cout << -1 << '\n';
    }



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
