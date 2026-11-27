#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pii;

map<string, bool> used;

map<string, string> dict;

map<string, pair<ll, ll>> cnt;

void solve(){

    int n;

    cin >>n;

    vector<string> A(n);

    for(auto& i : A) {

            cin >> i;

            used[i] = 1;

    }

    int m;

    cin >> m;

    bool ok = 1;

    while(m--){

        string a, b, c;

        cin >> a >>b >> c;

        if (!used[a]) continue;

        if (dict[a] == ""){

            dict[a] = b;

        }

        else ok = 0;

        if (c[0] == 'i') cnt[a].second++;

        else cnt[a].first++;

    }

    if (ok){

        for(auto i : A) {

            cout << dict[i] << ' ';

            if(cnt[i].second != 0) ok = 0;

        }

        cout << '\n';

        if (ok) cout << "correct";

        else cout <<"incorrect";

        return;

    }

    ll tot = 1;

    ll cor = 1;

    for(auto i : A){

        cor *= cnt[i].first;

        tot *= cnt[i].first + cnt[i].second;

    }

    cout << cor << " correct\n";

    cout << tot-cor << " incorrect\n";

    return;

}

int main(){

    std::ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    solve();

    return 0;

}

