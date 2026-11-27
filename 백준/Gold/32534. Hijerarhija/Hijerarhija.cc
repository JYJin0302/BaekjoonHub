#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
 
    int n;
    cin >> n;

    int cnt = n;
    vector<int> inD(n+1);
    set<pair<int, int>> st;
    for(int i =0 ; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        inD[b]++;
        if (inD[b] == 1) cnt--;

        st.insert(mp(a, b));
    }

    if (cnt == 1) cout << "DA\n";
    else cout << "NE\n";

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;

        if (st.find(mp(a, b)) != st.end()){}
        else swap(a, b);

        inD[b]--;
        if (inD[b] == 0) cnt++;
        inD[a]++;
        if (inD[a] == 1) cnt--;

        if (cnt == 1) cout << "DA\n";
        else cout << "NE\n";
        st.erase(st.find(mp(a, b)));
        st.insert(mp(b, a));
    }

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
   // cin >> t;
    for(int i =0 ;i < t;i ++){
        solve();
    }


    return 0;
}