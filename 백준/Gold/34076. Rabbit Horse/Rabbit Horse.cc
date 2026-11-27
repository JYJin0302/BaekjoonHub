#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

bool cmp(array<int, 3>& a1, array<int, 3>& a2){
    return a2[0] * a1[1] > a1[0] * a2[1];
}
void solve(){

    int n;
    cin >> n;
    if (n <= 10){
        cout << string(n, 'A') << '\n';
        return;
    }

    int cur = 2;
    vector<array<int, 3>> tmp;
    string ts = "rabithorse";

    vector<int> cnt(10, 1);
    cnt[2] = 2;
    for(int i =0 ; i < 10; i++){
        if (i == 2) tmp.push_back({1, 3, i});
        else tmp.push_back({1, 2, i});
    }

    for(int i = 0; i < n - 11; i++){
        sort(all(tmp), cmp);
        cnt[tmp[0][2]]++;
        //cout << "ADD: " << tmp[0][2] << " => " <<1.0 * tmp[0][1] / tmp[0][0] << '\n';

        tmp[0][0]++;
        tmp[0][1]++;
    }

    for(int i = 0; i < 10; i++){
        cout << string(cnt[i], ts[i]);
    }
    cout << '\n';
    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}