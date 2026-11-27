#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >>s;

    int cnt0 = 0;
    for(auto i :s) cnt0 += (i == '0');

    int n = s.size();


    if (cnt0 > n/2){
        cout <<string(n, '1');
    }
    else if (n-cnt0 > n/2) cout <<string(n, '0');
    else {
        if(s[0] == '0') cout <<'1' << string(n-1, '0');
        else cout <<'0' <<string(n-1, '1');
    }


    return 0;
}
