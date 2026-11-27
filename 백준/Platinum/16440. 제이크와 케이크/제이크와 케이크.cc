#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string cake;
	int n;
	cin >> n;
	cin >> cake;
	int count_s = 0, count_k = 0;
	for (int i = 0; i < n / 2; i++) {
		if (cake[i] == 's')
			count_s++;
		else
			count_k++;
	}
	if (count_s == n / 4 && count_k == n / 4) {
		cout << 1 << endl;
		cout << n / 2 << endl;
	}
	else {
		count_s = 0;
		count_k = 0;
		int cut = 1;
		if (cake[0] == 's') count_s++;
		else count_k++;

		for (int i = cut + n / 2; i < n; i++) {
			if (cake[i] == 's')
				count_s++;
			else
				count_k++;
		}
		while (cut < n / 2 - 1) {
			if (count_s == n / 4 && count_k == n / 4)
				break;
			if (cake[cut] == 's')
				count_s++;
			else
				count_k++;
			if (cake[cut + n / 2] == 's')
				count_s--;
			else
				count_k--;
			cut++;
		}
		cout << 2 << endl;
		cout << cut << " " << cut + n / 2 << endl;
	}
	return 0;
}