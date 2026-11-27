#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

typedef long long ll;

int cnt1[200];
int cnt22[20000];
int cnt2[200];

void solve(){
    
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    for(auto f : A){
        cnt1[f % 100]++;
        cnt22[f % 10000]++;
    }

    for(int i = 0; i < 10000; i++){
        cnt2[i % 100] = max(cnt2[i % 100], cnt22[i]);
    }

    vector<pair<int, int>> c1;
    for(int i =0 ; i < 100; i++) c1.push_back(mp(cnt1[i], i));
    sort(all(c1));
    reverse(all(c1));

    int ans = 0;

    // 3
    for(int i =0 ; i < 3; i++){
        ans += c1[i].x * 500;
    }

    // 1 -> 3
    for(int j = 0; j < 100; j++){
        int val = 0;
        if (cnt1[j]){
            val += 300000;
        }
        else continue;

        int cnt = 0;
        for(int i = 0; i < 5 && cnt < 3; i++){
            if(c1[i].y == j) continue;
            cnt++;
            val += 500 * c1[i].x;
        }
        ans = max(ans, val);
    }

    // 2 -> 3
    for(int j = 0; j < 100; j++){
        int val = 0;
        if (cnt2[j]){
            val += 4000 * cnt2[j];
        }
        else continue;

        int cnt = 0;
        for(int i = 0; i < 5 && cnt < 3; i++){
            if(c1[i].y == j) continue;
            cnt++;
            val += 500 * c1[i].x;
        }
        ans = max(ans, val);
    }


    // 1 -> 2 -> 3

    for(int a = 0;a < 100; a++){
        if (!cnt1[a]) continue;
        for(int b = 0; b < 100; b++){
            if (!cnt1[b]) continue;
            if (a == b) continue;

            int val = 300000 + cnt2[b] * 4000;
            int cnt = 0;
            for(int i = 0; i < 7 && cnt < 3; i++){
                if(c1[i].y == a || c1[i].y == b) continue;
                cnt++;
                val += 500 * c1[i].x;
            }

            ans = max(ans, val);
        }
    }

    cout << ans << '\n';


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}