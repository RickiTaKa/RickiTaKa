#include <iostream>
#include <array>
#include <vector>

using namespace std;

vector<vector<char>> checkOthers(vector<vector<char>> g, int rows, int cols, int r, int c) {  // create out of bounds, use fill
	if (c < 0 || c >= cols || r < 0 || r >= rows) {
		return g;
	}
	if (g[r][c] == '*') {
		return g;
	}
	if (g[r][c] == '#') {
		return g;
	}

	g[r][c] = '#';

	g = checkOthers(g, rows, cols, r + 1, c);
	g = checkOthers(g, rows, cols, r - 1, c);
	g = checkOthers(g, rows, cols, r, c + 1);
	g = checkOthers(g, rows, cols, r, c - 1);
	g = checkOthers(g, rows, cols, r + 1, c - 1);
	g = checkOthers(g, rows, cols, r + 1, c + 1);
	g = checkOthers(g, rows, cols, r - 1, c + 1);
	g = checkOthers(g, rows, cols, r - 1, c - 1);

	return g;
}

int findTotal(vector<vector<char>> g, int r, int c) {
	int total = 0;

	for (int i = 0; i < r; i++) {
		for (int x = 0; x < c; x++) {
			if (g[i][x] == '@') {
				total++;
				g = checkOthers(g, r, c, i, x);
			}
		}
	}

	return total;
}

int main() {
	int rows, cols, total = 0, count = 0;
	string row;
	vector<vector<char>> grid;

	cin >> rows;
	cin >> cols;
	
	while (rows != 0 && cols != 0) {

		count++;

		for (int i = 0; i < rows; i++) {
			cin >> row;
			vector<char> v1(row.begin(), row.end());

			grid.push_back(v1);
		}

		total = findTotal(grid, rows, cols);

		if (total == 0) {
			cout << "Grid #" << count << " doesn't contain an oil deposit." << endl;
		}
		else if (total == 1) {
			cout << "Grid #" << count << " contains " << total << " oil deposit." << endl;
		}
		else {
			cout << "Grid #" << count << " contains " << total << " oil deposits." << endl;
		}

		grid.clear();

		cin >> rows;
		cin >> cols;
	}

}