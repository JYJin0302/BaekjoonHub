#include<bits/stdc++.h>
using namespace std;
using ld = long double;

ld noR[33];
ld yeR[33];
ld pow2[33];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int n, k;
    cin >> k >> n;

    pow2[0] = 1.0;
    for (int i = 1; i <= 30; i++) pow2[i] = pow2[i - 1] / 2;

    
    for (int i = 0; i <= k; i++) {
        ld res = 1.0 / (i + 1.0);
        for (int j = 2; j <= i; j++) {
            ld tres = 1.0 / j / (j + 1.0);
            tres *= 1 - pow2[j - 1];
            res += tres;
        }
        noR[i] = res;
    }

    for (int i = 2; i <= k; i++) {
        ld res = 1.0 / (i);
        res *= 1 - pow2[i-1];
        for (int j = 2; j < i; j++) {
            ld tres = 1.0 / j / (j + 1.0);
            tres *= 1 - pow2[j - 1];
            res += tres;
        }
        yeR[i] = res;
    }

    /*for (int i = 0; i <= 20; i++) {
       cout << i << ": " << noR[i] << ' ' << yeR[i] << '\n';
    }*/

    vector<pair<int, int>> inp;
    map<pair<int, int>, bool> used;
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        inp.push_back({ a, b });
        int ta = a, tb = b;

        int dist = 0;
        while (a != k && !used[{a, b}]) {
            dist++;
            a++;
            b = (b + 1) / 2;
        }


        if (used[{a, b}]) {
            ans += 1-pow2[dist-1];
            //cout << "found: " << dist << '\n';
        }
        else {
            ans += 1;
            // cout << "Not found\n";
        }

        used[{ta, tb}] = 1;
    }
    //cout << "Before n: " << ans << '\n';
    
    vector<int> cnt1(33), cnt2(33);
    if (used[{k, 1}]) cnt2[0] = 1;
    else cnt1[0] = 1;
    sort(inp.rbegin(), inp.rend());

    int ix = 0, currH = k;
    while (currH >= 1) {

        int rmvcnt = 0;

        while (ix < n && inp[ix].first == currH) {

            int dist = 0;
            int a, b;
            tie(a, b) = inp[ix];
            while (a != k) {
                a = a + 1;
                b = (b + 1) / 2;
                dist++;
                if (used[{a, b}]) break;
            }
            if (used[{a, b}]) {
                cnt2[dist]--;
            }
            else {
                cnt1[dist]--;
            }

            rmvcnt++;
            ix++;
        }

        //cout << "Currstate: \n";
        //for (int i = 0; i <= 30; i++) cout << cnt1[i] << ' ';
        //cout << '\n';
        //for (int i = 0; i <= 30; i++) cout << cnt2[i] << ' ';
        //cout << '\n';

        for (int i = 0; i <= 30; i++) {
            ans += cnt1[i] * noR[i];
            ans += cnt2[i] * yeR[i];
        }

        for (int i = k; i >= 1; i--) {
            cnt1[i] = cnt1[i - 1] * 2;
            cnt2[i] = cnt2[i - 1] * 2;
        }
        cnt1[0] = cnt2[0] = 0;
        cnt2[1] += 2 * rmvcnt;
        currH--;
    }

    cout << ans;

}
