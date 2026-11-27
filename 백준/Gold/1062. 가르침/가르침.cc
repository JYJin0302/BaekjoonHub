#include <bits/stdc++.h>
using namespace std;

vector<bool> check;
int n, k, ans = 0;
vector<string> A;

void backtrack(int f = 0, int cnt = 0) {
    if (cnt == k) {
        int temp = 0;
        for (string s : A) {
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (s[i] == '1' && !check[i]) {
                    ok = false;
                    break;
                }
            }

            temp += ok;
        }

        ans = max(ans, temp);
        return;
    }

    for (int i = f; i < 26; i++) {
        if (check[i]) continue;

        check[i] = 1;
        backtrack(i + 1, cnt + 1);
        check[i] = 0;
    }
}



int main() {

    
    cin >> n >> k;

    check = vector<bool>(26);

    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string temp(26, '0');

        for (char k : s) {
            temp[k - 'a'] = '1';
        }
        A.push_back(temp);
    }

    if (k < 5) {
        cout << 0;
        return 0;
    }

    check['a' - 'a'] = 1;
    check['c' - 'a'] = 1;
    check['n' - 'a'] = 1;
    check['t' - 'a'] = 1;
    check['i' - 'a'] = 1;

    k -= 5;

    backtrack();

    cout << ans;
}