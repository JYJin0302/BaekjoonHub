#include <bits/stdc++.h>
using namespace std;

int n;
int conv(string s){


    vector<int> rdx(n + 1);
    rdx[n] = n;
    for(int i = n-1; i >= 0; i--){
        if (s[i] == '1') rdx[i] = i;
        else rdx[i] = rdx[i+1];
    }

    int l = 0;
    int ix = 0;
    while(ix < n){
        while(l < n && s[l] == '1') l++;
        ix = max(ix, l);

        int tl = rdx[ix];
        
        if (tl == n) break;
        int tr = tl;
        while(tr < n && s[tr] == '1') tr++;
       // cout << l << ' '<< ix << ' '<< tl << ' ' << tr << endl;

        int len = tr - tl;
        while(len & 1){
            int lenL = tl - l;
            int lenR = rdx[tr] - tr;

            if(tr == n){
                tl--;
                len++;
                break;
            }
            
            if(lenL <= lenR){
                len += 2*lenL;
                tl -= lenL;
                tr += lenL;
                break;
            }

            tl -= lenR;
            tr += lenR;
            while(tr < n && s[tr] == '1') tr++;

            len = tr - tl;
        }

        for(int i = tl; i < tr; i++) s[i] = '0';
        for(int j = 0; j < len; j++) s[l + j] = '1';
        
        l += len;
        ix = tr + 1;
    }
    while(l < n && s[l] == '1') l++;
    //cout << s << ' ';

    return l;
}


void solve(){
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int v1 = conv(s1); //cout <<v1 << ' ';
    int v2 = conv(s2); //cout << v2 << ' ';

    if( (v1+1)/2 == (v2 + 1)/2) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}