
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> idx2str = {"top", "bottom", "left", "right"};
map<string, int> str2idx;
vector<int> val;

void getNext(){

    for(int i = 0; i < 4; i++){

        int cv= 0;
        for(int j = 0; j < 4; j++){
            if (j != i) cv ^= val[j];
        }

        if (val[i] > cv){
            cout << idx2str[i] << ' ' << val[i] - cv << endl;
            val[i] = cv;
            return;
        }
    }
    assert(0);
}

void solve(){

    int r, c, k;
    cin >> r >> c >> k;

    int mr = 1e7, Mr= -1, mc = 1e7, Mc = -1;
    while(k--){

        int a, b;
        cin >> a>> b;
        mr = min(mr, a);
        Mr = max(Mr, a);

        mc = min(mc, b);
        Mc = max(Mc, b);
    }

    idx2str = {"top", "bottom", "left", "right"};
    for(int i = 0; i < 4; i++){
        str2idx[idx2str[i]] = i;
    }
    val = {mr - 1, r - Mr, mc-1, c - Mc};

    int cv = val[0] ^ val[1];
    cv ^= val[2];
    cv ^= val[3];

    if (cv > 0){
        // take first
        getNext();
    }
    else cout << "pass"<< endl;

    while(1){

        string s;
        cin >> s;

        if (s == "yuck!") return;

        int x;
        cin >> x;

        val[str2idx[s]] -= x;

        getNext();
    }

}


int main(){
    ios::sync_with_stdio(false);
    //cin.tie(0);
   // cout.tie(NULL);

    cout.flush();
    solve();
    return 0;
}
