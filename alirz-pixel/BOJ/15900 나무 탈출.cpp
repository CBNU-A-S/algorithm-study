#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> tree;
vector<int> path_legnth;
stack<int> child;
int n, cnt = 0;

void bfs() {
	queue<int> q;
	vector<int> v(n);

	q.push(0);
	v[0] = true;

	int depth = -1;
	while (!q.empty()) {
		int size = q.size();
		depth++;

		while (size--) {
			int front = q.front();
			q.pop();

			for (auto i : tree[front]) {
				if (v[i]) {
					continue;
				}

				v[i] = true;

				q.push(i);
			}

			if (front != 0 && tree[front].size() == 1) {
				cnt += depth;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	path_legnth.assign(n, 0);

	tree.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs();

	cout << (cnt % 2 ? "Yes" : "No");

	return 0;
}
