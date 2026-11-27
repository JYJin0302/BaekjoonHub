#include <bits/stdc++.h>
using namespace std;

int n;
char a, b, c;
string letters;
vector<vector<char>> base;

void pre(int i = 0) {
    cout << letters[i];
    if (base[i][0] != '.') {
        pre(base[i][0] - 'A');
    }
    if (base[i][1] != '.') {
        pre(base[i][1] - 'A');
    }
}
void mid(int i = 0) {
    if (base[i][0] != '.') {
        mid(base[i][0] - 'A');
    }
    cout << letters[i];
    if (base[i][1] != '.') {
        mid(base[i][1] - 'A');
    }
}
void post(int i = 0) {
    if (base[i][0] != '.') {
        post(base[i][0] - 'A');
    }
    if (base[i][1] != '.') {
        post(base[i][1] - 'A');
    }
    cout << letters[i];
}



int main() {
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> n;
    base = vector<vector<char>>(26);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        base[a - 'A'].push_back(b);
        base[a - 'A'].push_back(c);
    }


    pre(); cout << '\n';
    mid(); cout << '\n';
    post();

}