#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> ans;

int search(int ind) {
    int cnt = 0;
    int temp = 0;
    while (cnt <= ind) {
        if (ans[temp] != 0) temp++;
        else { cnt++, temp++; }
    }
    return temp - 1;
}



int main() {

    cin >> n;
    vector<int> base(n);
    for (auto& i : base) cin >> i;

    ans = vector<int>(n);
    for (int i = 1; i <= n; i++) {
        int t = search(base[i - 1]);
        ans[t] = i;
    }
    for (int i : ans) cout << i << ' ';
}