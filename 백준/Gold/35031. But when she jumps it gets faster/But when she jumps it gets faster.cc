#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int nxt[1001010];
int cnt[1001010];
void solve(){

    ll n, k, l;
    cin >> n >> l >> k;

    memset(nxt, -1, sizeof nxt);
    vector<int> A(k);
    for(auto& i : A) {
        cin >> i;
        i--;
        nxt[i] = i;
        cnt[i]++;
    }

    for(int i = 1; i < l; i++) cnt[i] += cnt[i-1];

    if(nxt[l-1] == -1) nxt[l-1] = A[0];
    for(int i = l-2; i >= 0; i--){
        if (nxt[i] == -1) nxt[i] = nxt[i+1];
    }

    // for(int i =0 ; i< l; i++) cout << nxt[i] << ' ';
    // cout << '\n';

    ll curN = 0;
    ll curS = 1;
    int ix = 0;
    ll ans = 0;

    while(curN < n){

        //cout << "state: " << curS << ' ' << curN << ' ' << ix << ' ' << ans << '\n';
        if (curS < l){
            
            int ni = nxt[ix];
            if (ni < ix){
                if (curN == n-1){
                    ans += (l-ix + curS - 1) / curS;
                    curN++;
                    break;
                }
                int len = l-ix + ni + 1;
                int frameMove = (len + curS - 1) / curS;
                ans += frameMove;
                
                curN += (ix + curS * frameMove) / l;
                int ni = (ix + curS * frameMove) % l;
                if((ix + curS * frameMove) / l) curS += ((ix + curS * frameMove) / l - 1) * k;
                curS += (ni ? cnt[ni-1] : 0);
                curS += cnt[l-1] - (ix ? cnt[ix-1] : 0);
                ix = ni;
            }
            else{
                int len = ni - ix + 1;
                int frameMove = (len + curS - 1) / curS;
                ans += frameMove;
                
                curN += (ix + curS * frameMove) / l;
                int ni = (ix + curS * frameMove) % l;
                if ((ix + curS * frameMove) / l != 0){
                    curS += k * ((ix + curS * frameMove) / l - 1);
                    curS += (ni ? cnt[ni-1] : 0);
                    curS += cnt[l-1] - (ix ? cnt[ix-1] : 0);
                }
                else{
                    curS += cnt[ni-1] - (ix ? cnt[ix-1] : 0);
                }
                ix = ni;
            }
        }
        else{
            
            ll jmpCnt = 0;
            int ni = (ix + curS) % l;
            curN += (ix + curS) / l;
            jmpCnt += ((ix + curS) / l - 1) * k;
            jmpCnt += cnt[l-1] - (ix ? cnt[ix-1] : 0);
            jmpCnt += (ni ? cnt[ni-1] : 0);

            ans++;
            curS += jmpCnt;
            ix = ni;
        }
    }

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
