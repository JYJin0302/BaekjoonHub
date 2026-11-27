#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9+7;

#define all(x) x.begin(), x.end()
#define no {cout << "impossible\n"; return;}


void solve(){

    int n, h;
    cin >> n >> h;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    if(*max_element(all(A)) > h) {
        no;
    }

    for(auto& i : A) i = h - i;

    vector<int> res(n);
    int ix = 0, p = 0;
    for(int i = 0; i < n ;i++){
        if (A[i] & 1){
            if(ix & 1){
                p ^= 1;
            }
            else{
                if(p == 0) ix++;
                else ix--;
            }
        }
        else{
            if(ix & 1){
                if (p == 0) ix++;
                else ix--;
            }
            else{
                p ^= 1;
            }
        }
        res[i] = ix;
        if(ix == 0) p = 0;
    }

    if(ix == 0  || (ix == 1 && p == 1)) {}
    else no;

    for(int i = 0; i < n; i++){
        if(res[i] > A[i]) no;
    }
    cout << "possible\n";
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}