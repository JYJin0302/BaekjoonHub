#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string> A;
    string s;
    cin >> s;
    while (s != "-") {
        string t(26, '0');
        for (auto i : s) t[i - 'A']++;
        A.push_back(t);

        cin >> s;
    }


    cin >> s;
    while (s != "#") {
        vector<int> cnt(26, A.size());
        string t(26, '0');
        for (char i : s) t[i - 'A'] ++;

        for (auto i : A) {
            vector<bool> c(26);
            bool ok = 1;
            for (int k = 0; k < 26; k++) {
                if (t[k] < i[k]) ok = 0;
            }

            if (ok) {
                for (int k = 0; k < 26; k++) {
                    if (t[k] != '0' && i[k] == '0') {
                        cnt[k]--;
                    }
                }
            }
            else for (int k = 0; k < 26; k++) cnt[k]--;
        }

        int minn = *min_element(cnt.begin(), cnt.end());

        for (int i = 0; i < 26; i++) if (t[i] == '0') cnt[i] = -1;
        int maxx = *max_element(cnt.begin(), cnt.end());

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == minn && t[i] != '0') cout << char(i + 'A');
        }
        cout << ' ' << minn << ' ';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == maxx && t[i] != '0') cout << char(i + 'A');
        }
        cout << ' ' << maxx << '\n';
        
        cin >> s;
    }

}