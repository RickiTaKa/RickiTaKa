#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLayers(vector<int> l) {
	vector<int> count;
	int tot, max;

	for (int i = 0; i < l.size(); i++) {

		if (i == 0) {
			tot = 1;
			count.push_back(tot);
		}
		else {
			max = 0;

			for (int c = i; c > 0; c--) {

				if (l[i] <= l[c - 1]) {

					if (max <= count[c - 1]) {
						max = count[c - 1] + 1;
					}

				}
				else {

					if (max <= 1) {
						max = 1;
					}

				}

			}

			count.push_back(max);
		}
	}

	max = *max_element(count.begin(), count.end());
	
	return max;
}

int main() {

	vector<int> layers;
	int N, num, result;
	cin >> N;

	while (N != 0) {

		for (int i = 0; i < N; i++) {
			cin >> num;
			layers.push_back(num);
		}

		result = findLayers(layers);
		cout << result << endl;

		layers.clear();
		cin >> N;
	}
	
}
