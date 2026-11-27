#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, l, r, h;
    cin >> n;
    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        cin >> l >> h >> r;
        A.push_back({ l, -h });
        A.push_back({ r, h });
    }

    sort(A.begin(), A.end());

    priority_queue<int> pq;
    map<int, int> decrease;

    int currh = 0;
    for (auto i : A) {
        int a, b;
        tie(a, b) = i;

        if (b < 0) {
            b *= -1;
            if (b > currh) {
                cout << a << ' ' << b << ' ';
                currh = b;
            }
            pq.push(b);
        }
        else {
            decrease[b]++;
            while (!pq.empty() && decrease[pq.top()] > 0) {
                decrease[pq.top()]--;
                pq.pop();
            }
            int newh = 0;
            if (!pq.empty()) newh = pq.top();

            if (newh != currh) {
                currh = newh;
                cout << a << ' ' << newh << ' ';
            }
        }
    }
}