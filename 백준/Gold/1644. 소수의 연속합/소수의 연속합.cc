#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> primes;
vector<int> primeList;


int main() {
    cin >> n;
    primes = vector<bool>(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (!primes[i]) continue;
        primeList.push_back(i);
        for (int j = i * 2; j <= n; j += i) {
            primes[j] = 0;
        }
    }
    if (n == 1) {
        cout << 0; return 0;
    }

    int cnt = 0;
    int l = 0, r = 0;
    int ss = primeList[0];
    while (r < primeList.size() && l <= r) {
        if (ss < n) {
            if (r == primeList.size() - 1) break;
            r++;
            ss += primeList[r];
        }
        else if (ss >= n) {
            if (ss == n) cnt++;
            ss -= primeList[l];
            l++;
        }
    }

    cout << cnt;

}