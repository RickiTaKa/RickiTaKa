#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
using std::priority_queue;

#define INF INT8_MAX

int dijkstra(vector<int> cupSize, int n, int goal) {

	int weight = -1;
	set<vector<int>> breadcrumb;
	priority_queue <pair<int, vector<int>>> q;
	map<vector<int>, int> d;
	vector<int> state(n, 0);

	state.at(0) = cupSize.at(0);
	d[state] = 0;

	q.push({ 0, state });

	while (!q.empty() && weight == -1) {

		int poured = q.top().first;
		vector<int> temp = q.top().second;
		q.pop();

		if (!breadcrumb.count(temp)) {

			breadcrumb.insert(temp);

			if (temp.at(0) == goal) {
				weight = d[temp];
			}

			for (int c = 0; c < n; c++) {

				for (int x = 0; x < n; x++) {

					if (c != x) {

						vector<int> current = temp;
						int total;

						total = min(temp.at(c), cupSize.at(x) - temp.at(x));

						current.at(x) += total;
						current.at(c) -= total;

						if (!d.count(current)) {
							d[current] = INF;
						}

						int sum = d[temp] + total;

						if (sum < d[current]) {
							d[current] = sum;
							q.push({ -d[current], current });
						}

					}
				}

			}

		}

	}
	
	return weight;

}

int main() {

	int n, cup, goal, tests, answer;

	cin >> tests;

	for (int i = 0; i < tests; i++) {

		vector<int> cupsSize;

		cin >> n;

		for (int c = 0; c < n; c++) {

			cin >> cup;
			cupsSize.push_back(cup);
		
		}

		cin >> goal;

		answer = dijkstra(cupsSize, n, goal);
		
		if (answer == -1) {
			cout << "impossible" << endl;
		}
		else {
			cout << answer << endl;
		}
		
		cupsSize.clear();

	}
}