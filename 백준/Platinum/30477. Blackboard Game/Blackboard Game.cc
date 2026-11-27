
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){

    int n;
    cin >>n;

    map<int, int> cnt;
    for(int i = 0; i < n*3; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> cntL;
    for(auto i : cnt){
        cntL.push_back(i.second);
    }
    bool ok = 1;
    for(auto f : cntL) if (f % 3 != 0) ok = 0;

    if (ok) cout << "N";
    else cout <<"Y";

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
