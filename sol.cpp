#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	// view the image in this repository for better understanding
	int mid = -1;
	string move = "";
	if (n % 2 == 0) {
		// if n is even and k is less than or equal to the middle position, then it is 
		// better to start at position 1, otherwise, start at the end
		mid = n / 2;
		if (k <= mid) {
			move = "LEFT";
		} else {
			move = "RIGHT";
		}
	} else {
		// if n is odd and k is less than the middle position, then it is
		// better to start at position 1, otherwise, start at the end
		mid = (n + 1) / 2;
		if (k < mid) {
			move = "LEFT";
		} else {
			move = "RIGHT";
		}
	}
	// if between 1 and n, then we need to choose the smaller distance between 1 and n
	if (k > 1 && k < n) {
		for (int i = 0; i < min(k - 1, n - k); i++) {
			cout << move << '\n';
		}
	}
	if (move == "LEFT") {
		// if the chosen move is left, then we will start at position 1 (beginning character)
		for (int i = 0; i < n; i++) {
			cout << "PRINT" << " " << s[i] << '\n';
			if (i < n - 1) {
				cout << "RIGHT" << '\n';
			}
		}
	} else {
		// if the chosen move is right, then we will start at position (n - 1) (ending character)
		for (int i = n - 1; i >= 0; i--) {
			cout << "PRINT" << " " << s[i] << '\n';
			if (i > 0) {
				cout << "LEFT" << '\n';
			}
		}
	}
	return 0;
}
