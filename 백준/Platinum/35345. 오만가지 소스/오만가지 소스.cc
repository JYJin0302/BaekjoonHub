#include <vector>

#include "sauce.h"

using std::vector;

vector<int> L0[3], R0[3];

int LLR[3][3][3];  // 9
int LRR[3][3][3];  // 9
int LL[3][3];      // 3
int RR[3][3];      // 3
int LR[3][3];      // 9
int L[3], R[3];    // 6

int solve(int N) {
	vector<int> tmp;
	for (int i = 0; i < N / 2; i++) tmp.push_back(i);
	int valL = query(tmp);
	tmp.clear();
	for (int i = N / 2; i < N; i++) tmp.push_back(i);
	int valR = query(tmp);

	for (int i = 0; i < N / 2; i++) { L0[i % 3].push_back(i); }
	for (int i = N / 2; i < N; i++) { R0[i % 3].push_back(i); }

	for (int a = 0; a < 3; a++) {
		for (int b = a + 1; b < 3; b++) {
			for (int c = 0; c < 3; c++) {
				tmp.clear();
				for (auto f : L0[a]) tmp.push_back(f);
				for (auto f : L0[b]) tmp.push_back(f);
				for (auto f : R0[c]) tmp.push_back(f);

				LLR[a][b][c] = query(tmp);

				tmp.clear();
				for (auto f : R0[a]) tmp.push_back(f);
				for (auto f : R0[b]) tmp.push_back(f);
				for (auto f : L0[c]) tmp.push_back(f);

				LRR[c][a][b] = query(tmp);
			}
		}
	}

	for (int a = 0; a < 3; a++) {
		for (int b = a + 1; b < 3; b++) {
			tmp.clear();
			for (auto f : L0[a]) tmp.push_back(f);
			for (auto f : L0[b]) tmp.push_back(f);

			LL[a][b] = query(tmp);

			tmp.clear();
			for (auto f : R0[a]) tmp.push_back(f);
			for (auto f : R0[b]) tmp.push_back(f);

			RR[a][b] = query(tmp);
		}
	}

	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			tmp.clear();
			for (auto f : L0[a]) tmp.push_back(f);
			for (auto f : R0[b]) tmp.push_back(f);

			LR[a][b] = query(tmp);
		}
	}

	for (int a = 0; a < 3; a++) {
		tmp.clear();
		for (auto f : L0[a]) tmp.push_back(f);

		L[a] = query(tmp);

		tmp.clear();
		for (auto f : R0[a]) tmp.push_back(f);

		R[a] = query(tmp);
	}

	int ans = valL + valR;

	// add two
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) { ans += LR[a][b] - L[a] - R[b]; }
	}

	// add three
	for (int a = 0; a < 3; a++) {
		for (int b = a + 1; b < 3; b++) {
			for (int c = 0; c < 3; c++) {
				ans += LLR[a][b][c] - LR[a][c] - LR[b][c] - LL[a][b] + L[a] + L[b] + R[c];
				ans += LRR[c][a][b] - LR[c][a] - LR[c][b] - RR[a][b] + L[c] + R[a] + R[b];
			}
		}
	}

	return ans;
}
