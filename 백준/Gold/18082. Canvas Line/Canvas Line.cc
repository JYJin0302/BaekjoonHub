
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int l[2020], r[2020];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >>n;

    for(int i = 0; i <n ;i++){
        cin >>l[i] >>r[i];
    }

    vector<int> cnt(n);

    map<int, bool> isin;

    int p;
    cin >>p;
    for(int i = 0; i <p; i++){
        int x;
        cin >> x;
        isin[x] = 1;

        for(int j = 0; j <n; j++){
            if (l[j] <= x && x <= r[j]) cnt[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        if (cnt[i] >= 3){
            cout << "impossible";
            return 0;
        }
    }

    vector<int> ans;
    for(int i = 0; i <n; i++){
        if (cnt[i] == 2) continue;

        if (i +1 < n && cnt[i+1] < 2 && !isin[r[i]] && r[i] == l[i+1]){
            // middle
            ans.push_back(r[i]);
            isin[r[i]] = 1;
            cnt[i+1]++;
            cnt[i]++;
        }

        for(int j = l[i]+1; j < r[i]; j++){
            if (cnt[i] == 2) break;
            if (!isin[j]){
                isin[j] = 1;
                cnt[i]++;
                ans.push_back(j);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout <<ans.size()<<'\n';
    for(auto i:ans) cout <<i <<' ';

}
