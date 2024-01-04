#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void convert2m(vector<int>r) {

	int zeros = 0;

	for (auto i : r) {
		if (i == 0) {
			zeros++;
		}
	}

	if (zeros == r.size()) {
		cout << "@" << endl;
	}
	else {

		for (int i = r.size() - 1; i >= 0; i--) {

			int temp = r[i];

			if (temp == 0) {
				cout << '@';
			}

			if (temp < 5 || temp % 5 != 0) {
				if (temp < 5) {
					for (int x = 0; x < r[i]; x++) {
						cout << '*';
						temp -= 1;
					}
				}
				else {

					int rem = temp % 5;

					for (int x = 0; x < rem; x++) {
						cout << '*';
						temp -= 1;
					}
				}

				cout << endl;
			}

			if (r[i] >= 5) {

				while (temp >= 5) {
					cout << "-----";
					temp -= 5;
					cout << endl;
				}
			}

			if (i != 0) {
				cout << endl;
			}
		}
	}
}

void convert2d(vector<string> m, vector<int> &n) {

	int temp = 0;

	for (int i = 0; i < m.size(); i++) {

		if (m[i] == " ") {
			n.push_back(temp);
			temp = 0;
		}

		else {
			if (m[i] == "-----") {
				temp += 5;
			}
				
			else {
				for (int x = 0; x < m[i].size(); x++) {
					if (m[i][x] == '*')
						temp += 1;
				}
			}

			if (i == m.size() - 1) {
				n.push_back(temp);
			}
		}
	}
}

void sum(vector<int> n1, vector<int> n2, vector<int> &r) {

	int temp;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int i = n1.size() > n2.size() ? n1.size() : n2.size();

	for (int x = 0; x < i; x++) {

		temp = 0;

		if (x >= n2.size() || x >= n1.size()) {

			if (x >= n2.size()) {
				temp += n1[x] + 0;
			}
			else {
				temp += n2[x] + 0;
			}

			r[x] = temp;
		}

		else {

			temp = n1[x] + n2[x];

			if (temp >= 20) {
				if (x + 1 > n1.size() - 1) {
					n1.resize(n1.size() + 1);
					r.resize(n1.size());
				}

				n1[x + 1] += 1;

				if (temp >= 20) {
					r[x + 1]++;
				}

				r[x] = temp % 20;
			}

			else {
				r[x] = temp;
			}
		}
	}
}

void sub(vector<int>n1, vector<int>n2, vector<int> &r) {

	int temp;

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int i = n1.size() < n2.size() ? n1.size() : n2.size();

	for (int x = 0; x < i; x++) {

		if (x >= n2.size() || x >= n1.size()) {

			if (x >= n2.size()) {
				r.push_back(n1[x]);
			}
			else {
				r.push_back(n2[x]);
			}
		}

		else
		{
			if (n2[x] > n1[x]) {
				n1[x + 1]--;
				n1[x] += 20;
			}

			r.push_back(n1[x] - n2[x]);
		}
	}
}

int main() {
	string label, x, num;
	int hash = 0;
	int c, actualSize;
	char oper;
	vector<string> mayan1, mayan2;
	vector<int> num1, num2;

	getline(cin, label);

	while (getline(cin, num) && num != "END") {

		if (num == "#") {

			hash++;
			if (hash == 2) {
				convert2d(mayan1, num1);
				convert2d(mayan2, num2);

				c = num1.size() > num2.size() ? num1.size() : num2.size();

				vector<int> result(c);

				if (oper == '+') {
					sum(num1, num2, result);
				}
				else {
					result.resize(0);

					sub(num1, num2, result);
				}

				cout << label << endl;
				convert2m(result);
				cout << "#\n";

				mayan1.clear();
				num1.clear();
				mayan2.clear();
				num2.clear();
				result.clear();
				hash = 0;

				getline(cin, label);

				if (label == "END") {
					break;
				}

				continue;
			}
			else cin >> oper;
		}

		if (!num.empty()) {
			if (hash == 0)
				mayan1.push_back(num);
			else if (hash == 1 && num != "#")
				mayan2.push_back(num);
		}

		else {
			if (hash == 0)
				mayan1.push_back(" ");
			else if (hash == 1 && !num2.empty())
				mayan2.push_back(" ");
		}

	}
}