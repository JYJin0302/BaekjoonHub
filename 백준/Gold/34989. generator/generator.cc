#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    string s;
    cin >> s;

    if (s[0] == 'y'){

        for(int k = 1; k <= n/2; k++){
            bool ok = 1;

            for(int i = 0; i < k; i++){
                int v1 = A[i];
                int v2 = A[n-k+i];

                if (v1 == v2 || v1 == 0 || v2 == 0) {}
                else ok = 0;
            }

            if (!ok) continue;

            for(int i = 0; i < k; i++){
                int v1 = A[i];
                int v2 = A[n-k+i];

                if (v1 == 0 && v2 == 0){
                    A[i] = 1;
                    A[n-k+i] = 1;
                }
                else if (v1 == 0) A[i] = A[n-k+i];
                else if (v2 == 0) A[n-k+i] = A[i];
            }
            for(int i = 0 ;i < n; i++){
                if (A[i] == 0) A[i] = 1;
            }
            for(auto f : A) cout << f<< ' ';
            cout << '\n';

            return;
        }

    }
    else{
        vector<bool> used(2020);
        for(auto f : A) used[f] = 1;
        int cur = 1;

        for(int i =0 ; i< n; i++){
            if (A[i] == 0){
                while(used[cur]) cur++;
                A[i] = cur++;
            }
        }

        for(auto f : A) cout <<f << ' ';
        cout << '\n';

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