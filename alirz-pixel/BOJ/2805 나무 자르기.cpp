#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;

	vector<long long> tree(n);
	for (auto& i : tree) {
		cin >> i;
	}

	sort(tree.begin(), tree.end());

	long long left = 0;
	long long right = tree[tree.size() - 1];
	long long mid = 0, ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int idx = lower_bound(tree.begin(), tree.end(), mid) - tree.begin();

		long long total = 0;
		for (int i = idx; i < n; i++) {
			total += tree[i] - mid;
		}


		if (m <= total) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}
