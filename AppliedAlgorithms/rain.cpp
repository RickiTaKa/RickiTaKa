#include <iostream>
#include <vector>

using namespace std;


int getResult(vector<int> s, vector<int> t) {

	vector<int> leak;
	int count = 0;
	int ls = 0;

	while (!t.empty()) {

		int lowest = 0, low, leaks = 0;
		
		for (int i = 0; i < s.size(); i++) {

			if (s[i] <= count) {
				leak.push_back(i);
			}

		}

		if (!leak.empty()) {

			lowest = t[leak[0]];
			low = leak[0];

			for (int i = 0; i < leak.size(); i++) {

				if (lowest > t[leak[i]]) {
					lowest = t[leak[i]];
					low = leak[i];
				}


			}

			t[low] = t[low] - 1;

			if (t[low] == 0) {
				s.erase(s.begin() + low);
				t.erase(t.begin() + low);
			}

		}

		leaks = leak.size();

		if (!leak.empty()) {
			ls += leaks;
			leak.clear();
			count++;
		}
		else {
			count++;
		}

	}

	return ls;

}

int main() {

	int ls, s, t, result;

	cin >> ls;

	while (ls != 0) {

		vector<int> startRain;
		vector<int> timeRain;

		for (int i = 0; i < ls; i++) {
			cin >> s;
			cin >> t;
			startRain.push_back(s);
			timeRain.push_back(t);
		}

		result = getResult(startRain, timeRain);

		cout << result << endl;

		startRain.clear();
		timeRain.clear();

		cin >> ls;
	}
}