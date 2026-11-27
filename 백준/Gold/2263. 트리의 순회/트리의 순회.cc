#include <bits/stdc++.h>
using namespace std;

vector<int> inorder, postorder;
void solve(int il, int ir, int pl, int pr) {  // in, post

	if (pl > pr || il > ir) return;
	int root = postorder[pr];
	
	if (pl == pr) {
		cout << root << ' ';
		return;
	}
	int mid = find(inorder.begin() + il, inorder.begin() + ir + 1, root) - inorder.begin();

	int lsize = mid - il;
	int rsize = ir - mid;

	cout << root << ' ';
	solve(il, mid - 1, pl, pl + lsize - 1);
	solve(mid + 1, ir, pl + lsize, pr - 1);
}


int main() {

	int n;
	cin >> n;
	inorder = vector<int>(n);
	postorder = vector<int>(n);

	for (auto& i : inorder) cin >> i;
	for (auto& i : postorder) cin >> i;

	solve(0, n - 1, 0, n - 1);
}