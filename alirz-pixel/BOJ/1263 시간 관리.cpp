
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;

	vector<pii> schedules(n);
	for (auto& schedule : schedules) {
		cin >> schedule.second >> schedule.first;
	}

	sort(schedules.begin(), schedules.end(), greater<pii>());

	int start_time = schedules[0].first;
	for (int i = 0; i < n; i++) {
		start_time -= schedules[i].second;

		if (i != n - 1) {
			start_time = min(start_time, schedules[i + 1].first);
		}
	}

	
	cout << ((start_time < 0) ? -1 : start_time);

	return 0;
}
