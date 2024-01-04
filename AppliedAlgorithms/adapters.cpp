#include <iostream>
#include <vector>
#include list

using namespace std;


struct adapts {
	char from;
	char to;
};

int convertChar(char c) {

	switch (c) {
		case 'A':
			return 0;
	
		case 'B': 
			return 1;

		case 'C':
			return 2;

		case 'D':
			return 3;

		case 'E':
			return 4;

		case 'F':
			return 5;

		case 'G':
			return 6;

		case 'H':
			return 7;

		case 'I':
			return 8;

		case 'J':
			return 9;

		case 'K':
			return 10;

		case 'L':
			return 11;

		case 'M':
			return 12;

		case 'N':
			return 13;

		case 'O':
			return 14;

		case 'P':
			return 15;

		case 'Q':
			return 16;

		case 'R':
			return 17;

		case 'S':
			return 18;

		case 'T':
			return 19;

		case 'U':
			return 20;

		case 'V':
			return 21;

		case 'W':
			return 22;

		case 'X':
			return 23;

		case 'Y':
			return 24;

		case 'Z':
			return 25;
	}
}

bool checkTo(vector<adapts> l, char T) {
	bool check = false;

	for (int i = 0; i < l.size(); i++) {
		if (l[i].to == T) {
			check = true;
		}
	}

	return check;
}

bool checkFrom(vector<adapts> l, char F) {
	bool check = false;

	for (int i = 0; i < l.size(); i++) {
		if (l[i].from == F) {
			check = true;
		}
	}

	return check;
}

bool findConnection(vector<adapts> l, char F, char T) {

	bool check;
	adapts temp;

	for (int i = 0; i < l.size(); i++) {

		temp = l[i];

		if (temp.from == F) {

			if (temp.to == T) {
				return true;
			}

			else {
				check = findConnection(l, temp.to, T);
				if (check == true) {
					return true;
				}
			}
		}
	}

	return false;
}

bool findAnswer(vector<adapts> l, char F, char T) {

	bool check;
	if (F == T) {
		return true;
	}

	if (checkTo(l, T) == false) {
		return false;
	}

	if (checkFrom(l, F) == false) {
		return false;
	}

	check = findConnection(l, F, T);
	return check;
}

vector<vector<int>> createGraph(vector<adapts> list) {

	int from, to;
	vector<vector<int>> temp[26];
	
	for (int i = 0; i < list.size(); i++) {
		from = convertChar(list[i].from);
		to = convertChar(list[i].to);

		temp[from].push_back(to);
	}
}

int main() {
	char f, t, count = 0;
	vector<adapts> list;
	vector<vector<int>> graph;
	adapts temp;
	bool answer;

	cin >> f;
	cin >> t;

	while (f != '-' && t != '-') {

		while (f != '-' && t != '-') {

			temp.from = f;
			temp.to = t;

			list.push_back(temp);

			count++;

			cin >> f;
			cin >> t;
		}

		graph = createGraph(list);

		cin >> f;
		cin >> t;

		while (f != '=' && t != '=') {

			if (count > 20) {
				answer = true;
			}
			else {
				answer = findAnswer(list, f, t);
			}

			if (answer == true) {
				cout << "Connected" << endl;
			}
			else {
				cout << "NOT Connected" << endl;
			}

			cin >> f;
			cin >> t;
		}

		list.clear();

		cin >> f;
		cin >> t;
	}
}