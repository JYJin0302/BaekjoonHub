#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dist[4][4];

int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> dist[i][j];
		}
	}

	bool valid = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {
				if (dist[i][j] + dist[j][k] < dist[k][i]) valid = 0;
				if (dist[j][k] + dist[k][i] < dist[i][j]) valid = 0;
				if (dist[k][i] + dist[i][j] < dist[j][k]) valid = 0;
			}
		}
	}

	int a = dist[0][1]; 
	int l1 = dist[0][2], l2 = dist[1][2];

	int d1 = dist[0][3], d2 = dist[1][3];

	long double t1 = (a * a + l1 * l1 - l2 * l2) / (2.0 * a);
	long double h1 = sqrtl(l1 * l1 - t1 * t1);

	long double t2 = (a * a + d1 * d1 - d2 * d2) / (2.0 * a);
	long double h2 = sqrtl(d1 * d1 - t2 * t2);

	long double maxDist = (h1 + h2) * (h1 + h2) + (t1 - t2) * (t1 - t2);
	long double minDist = (h1 - h2) * (h1 - h2) + (t1 - t2) * (t1 - t2);

	valid &= (minDist <= dist[2][3] * dist[2][3]) && (maxDist >= dist[2][3] * dist[2][3]);

	if (valid) cout << "YES";
	else cout << "NO";
}