#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define mp make_pair

int spt[20][202020];
int A[202020];
const ll mod = 1e9+7;

int gcd(int a, int b){
    if (a >b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a ,a);
}

int n;
void initSPT(){

    int N = n;
    int M = 31 - __builtin_clz(N);

    for(int i = 0; i < N; i++){
        spt[0][i] = A[i];
    }

    for(int j = 1; j <= M; j++){
        for(int i = 0; i < N; i++){
            if(i+(1 << j-1) < N){
                spt[j][i] = gcd(spt[j-1][i], spt[j-1][i + (1 << j-1)]);
            }
        }
    }

}

int getSPT(int l, int r){
    int d = r-l+1;
    int m = 31 - __builtin_clz(d);
    return gcd(spt[m][l], spt[m][r+1-(1<<m)]);
}

int L[202020], R[202020];

int getVal(int ix, int Arr[]){
    if(ix < 0 || ix >= n) return ix;
    if (Arr[ix] == ix) return ix;
    return Arr[ix] = getVal(Arr[ix], Arr);
}

void solve(){

    cin >> n;

    for(int i = 0; i < n; i++) cin >> A[i];

    initSPT();

    vector<pair<int, int>> B(n);
    for(int i = 0; i < n; i++){
        B[i] = mp(A[i], i);
        L[i] = R[i] = i;
    }
    sort(B.begin(), B.end());

    ll ans = 0;
    for(auto f : B){
        ll val = f.first;
        int ix = f.second;
       // cout << "Go:"<< ix << ' ' << val << '\n';

        L[ix] = ix-1;
        R[ix] = ix+1;
        int l = getVal(ix, L) + 1;
        int r = getVal(ix, R) - 1;

        //cout << "Range;"<< l << ' ' << r << '\n';
        // l .<=. ix .<=. r
        vector<pair<ll, ll>> resR, resL;

        int tx = ix;
        int cGCD = A[ix];

        while(tx <= r){

            int lx = tx;
            int rx = r;

            while(lx <= rx){

                int mid = (lx+rx)>>1;
                int res = getSPT(tx, mid);

                if (res % cGCD == 0){
                    // ok
                    lx = mid+1;
                }
                else{
                    rx = mid-1;
                }
            }

            // rx
            resR.push_back(mp(cGCD, rx - tx+1));
            tx = rx+1;

            if (tx <= r) cGCD = gcd(cGCD, A[tx]);
        }

        //cout << "RES R:\n";
        //for(auto f : resR) cout << f.first << ' '<< f.second << '\n';

        tx = ix;
        cGCD = A[ix];

        while(tx >= l){

            int lx = l;
            int rx = tx;

            while(lx <= rx){

                int mid = (lx+rx)>>1;
                int res = getSPT(mid, tx);

                if (res % cGCD == 0){
                    // ok
                    rx = mid-1;
                }
                else{
                    lx = mid+1;
                }
            }

            // rx
            resL.push_back(mp(cGCD, tx - rx));
            tx = rx;

            if (tx >= l) cGCD = gcd(cGCD, A[tx]);
        }
        //cout << "RES L:\n";
        //for(auto f : resL) cout << f.first << ' '<< f.second << '\n';

        for(auto f : resR){
            for(auto f2: resL){

                ll cnt = f.second;
                cnt *= f2.second;
                cnt %= mod;

                cnt = cnt * gcd(f.first, f2.first) % mod;
                cnt = cnt * val % mod;

                ans += cnt;
                ans %= mod;
            }
        }
    }

    cout << ans;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    solve();
    return 0;
}
