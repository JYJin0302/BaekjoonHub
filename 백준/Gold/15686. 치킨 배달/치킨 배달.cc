#include <bits/stdc++.h>
using namespace std;
#define INF 100000

int n, m, a, b, c, d, ans;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<vector<int>> city;
vector<bool> selected;

void cal() {
    int total = 0;
    for (int i = 0; i < home.size(); i++) {
        tie(a, b) = home[i];
        int temp = INF;
        for (int j = 0; j < selected.size(); j++) {
            if (!selected[j]) continue;
            tie(c, d) = chicken[j];
            temp = min(temp, abs(c - a) + abs(d - b));
        }
        total += temp;
    }
    ans = min(ans, total);
}



void select(int f = 0, int cnt = 0) {
    if (cnt == m) {
        cal();
        return;
    }

    for (int i = f; i < selected.size(); i++) {
        selected[i] = 1;
        select(i+1, cnt + 1);
        selected[i] = 0;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    city = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> city[i][j];
        if (city[i][j] == 2) chicken.push_back({ i, j });
        if (city[i][j] == 1) home.push_back({ i, j });
    }


    selected = vector<bool>(chicken.size());
    ans = INF;
    select();
    cout << ans;
}