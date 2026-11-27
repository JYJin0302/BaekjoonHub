#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair

void solve(){

    int n;

    cin >>n;

    vector<int> A, num;

    for(int i = 0; i < n; i++){

        int x;

        cin >>x;

        num.push_back(x);

        if (A.empty() || A.back() != x) A.push_back(x);

    }

    sort(num.begin(), num.end());

    num.erase(unique(num.begin(), num.end()), num.end());

    n = A.size();

    for(auto&i : A) i = lower_bound(num.begin(), num.end(), i) - num.begin() + 1;

    vector<pair<int, int>> B;

    for(int i = 0; i < n;i++) B.push_back(mp(A[i], i));

    sort(B.begin(), B.end());

    vector<vector<int>> lst;

    int ix = 0;

    while(ix < n){

        int nx = ix;

        vector<int> tmp;

        while(nx < n && B[nx].first == B[ix].first) {

            tmp.push_back(B[nx].second);

            nx++;

        }

        lst.push_back(tmp);

        ix = nx;

    }

    int ans = A.size() - 1;

    int tn = lst.size();

    vector<bool> used(n+1);

    for(int i = 0; i < tn; i++){

        int cnt = 0, nx = -1;

        for(auto f : lst[i]){

            if (f+1 < n && A[f+1] == A[f] +1 && (!used[f] || lst[i].size() == 1)) {

                nx = f+1;

                cnt++;

            }

        }

        //cout << "Curr: " << A[lst[i][0]] << " -> ";

        //for(auto f : lst[i]) cout << f << ' ';

        //cout <<'\n';

        //cout << cnt << ' ' << nx << '\n';

        if (cnt == 1){

            ans--;

            used[nx] = 1;

        }

        else if (cnt >= 2){

            ans--;

        }

        else{

        }

    }

    cout << ans;

}

int main(){

    std::ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    solve();

    return 0;

}

