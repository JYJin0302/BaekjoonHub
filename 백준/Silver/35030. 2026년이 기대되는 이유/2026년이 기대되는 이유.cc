#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool isP[101010];

int cnt[101010];

void solve(){

    for(int i =2  ;i <= 100010; i++){
        if (isP[i]) continue;
        for(int j = i*2; j <= 100010; j += i){
            isP[j] = 1; 
        }
    }
    isP[1] = 1;

    for(int i = 1; i <= 100000; i++){
        cnt[i] += cnt[i-1];
        if (isP[i+1]) {
            continue;
        }
        string s = to_string(i);
        int sn = (int)s.size();
        bool ok = 1;
        for(int j =0 ;j < sn-1; j++){
            int n1 = stoi(s.substr(0, j+1));
            int n2 = stoi(s.substr(j+1, sn));
            if (isP[n1*n2+1]) ok = 0;
        }

        if (ok) cnt[i]++;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << cnt[n] << '\n';
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
