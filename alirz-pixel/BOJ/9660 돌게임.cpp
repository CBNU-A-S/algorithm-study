#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	string ans = "SK";

	int who_is_win = n % 7;
	if (who_is_win == 2 || who_is_win == 0) {
		ans = "CY";
	}

	cout << ans;

	return 0;
}
