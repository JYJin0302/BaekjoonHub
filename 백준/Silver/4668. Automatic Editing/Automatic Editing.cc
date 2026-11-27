#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n) {
        vector<pair<string, string>> A(n);
        for (auto& i : A) {
            getline(cin, i.first);
            getline(cin, i.second);
        }

        string str;
        getline(cin, str);

        for (int i = 0; i < n; i++) {
            string a, b;
            tie(a, b) = A[i];
            while (str.find(a) != string::npos) {
                str.replace(str.find(a), a.size(), b);
            }
        }

        cout << str << '\n';
        cin >> n;
        cin.ignore();
    }
}