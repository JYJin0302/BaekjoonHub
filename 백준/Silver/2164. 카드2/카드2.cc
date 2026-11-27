#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    int top = dq.front();
    dq.pop_front();
    while (!dq.empty()) {
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
        top = dq.front();
        dq.pop_front();
    }
    cout << top;
}