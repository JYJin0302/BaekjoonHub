#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001

vector<int> seg; // index
vector<int> inp;

void init(int l, int r, int n) {
	if (l == r) return;
	int mid = (l + r) / 2;

	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);

	if (inp[seg[n * 2]] <= inp[seg[n * 2 + 1]]) seg[n] = seg[n * 2];
	else seg[n] = seg[n * 2 + 1];
}

void update(int l, int r, int n, int d) {
	if (l > d || r < d) return;
	if (l == d && r == d) return;

	int mid = (l + r) / 2;

	update(l, mid, n * 2, d);
	update(mid + 1, r, n * 2 + 1, d);

	if (inp[seg[n * 2]] <= inp[seg[n * 2 + 1]]) seg[n] = seg[n * 2];
	else seg[n] = seg[n * 2 + 1];
}

int search(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return -1;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid = (l+r)/2;
    
    int t1 = search(l, mid, n*2, sl, sr);
    int t2 = search(mid+1, r, n*2+1, sl, sr);
    if (t2 == -1) return t1;
    if (t1 == -1) return t2;
    
    if (inp[t1] <= inp[t2]) return t1;
    else return t2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int size = 1;
	while (size < n) size *= 2;
	inp = vector<int>(size + 1);
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
	}

	for (int i = n+1; i <= size; i++) {
		inp[i] = INF;
	}
	

	seg = vector<int>(size * 2);
	for (int i = 0; i < size; i++) {
		seg[size + i] = i + 1;
	}

	init(size, size * 2 - 1, 1);

	int m, a, b, c;
	cin >> m;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 2) {
             cout << search(size, size*2-1, 1, size - 1 + b, size - 1 + c) << '\n';
        }
		else {
			inp[b] = c;
			update(size, size * 2 - 1, 1, size + b-1);
		}
	}
}