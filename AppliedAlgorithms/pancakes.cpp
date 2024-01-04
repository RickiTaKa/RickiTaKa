#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

vector<char> flip(vector<char> pancake, int turns) {
	
	reverse(pancake.end() - turns, pancake.end());

	for (int c = pancake.size() - turns; c < pancake.size(); c++) {
		if (isupper(pancake[c])) {
			pancake[c] = tolower(pancake[c]);
		}
		else {
			pancake[c] = toupper(pancake[c]);
		}
	}

	return pancake;
}

int flippingPancakes(vector<char> pancakes)
{
	set<vector<char>> breadcrumbs;
	vector<char> final;
	queue<vector<char>> q;
	map<vector<char>, int> d;
	int total;

	for (int c = 0; c < pancakes.size(); c++) {

		final.push_back(toupper(pancakes.at(c)));
		sort(final.begin(), final.end());

	}

	q.push(pancakes);
	breadcrumbs.insert(pancakes);
	d[pancakes] = 0;

	while (!q.empty() && !breadcrumbs.count(final)) {

		vector<char> pancake = q.front();
		q.pop();

		for (int x = 1; x <= pancake.size(); x++) {

			vector<char> found = flip(pancake, x);

			if (!breadcrumbs.count(found)) {

				breadcrumbs.insert(found);
				d[found] = d[pancake] + 1;
				q.push(found);

			}

		}

	}

	total = d[final];

	return total;
}

int main() {

	string pancake;
	vector<char> pancakes;
	int result;

	cin >> pancake;

	while (pancake != "0") {

		vector<char> pancakes(pancake.begin(), pancake.end());

		result = flippingPancakes(pancakes);

		cout << result << endl;

		pancakes.clear();

		cin >> pancake;
	}


}