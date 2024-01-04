#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveCanal(vector<vector<int>> g, int col, int row) {

	for (int i = 1; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (j > 0 && j < col - 1) {
				g[i][j] += max(g[i - 1][j], max(g[i - 1][j - 1], g[i - 1][j + 1]));
			}

			else if (j > 0) {
				g[i][j] += max(g[i - 1][j], g[i - 1][j - 1]);
			}

			else if (j < col - 1) {
				g[i][j] += max(g[i - 1][j], g[i - 1][j + 1]);
			}
		}
	}
	int res = 0;

	for (int j = 0; j < col; j++) {
		res = max(g[row - 1][j], res);
	}

	return res;
}

int main() {

	int col, row, num, result;
	vector<vector<int>> grid;
	vector<int> r;

	cin >> col;
	cin >> row;

	while (row != 0 && col != 0) {

		for (int i = 0; i < row; i++) {
			for (int c = 0; c < col; c++) {
				cin >> num;
				r.push_back(num);
			}
			grid.push_back(r);
			r.clear();
		}
		
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 0) {
					grid[i][j] = -100;
				}
			}
		}
		

		result = solveCanal(grid, col, row);

		cout << result << endl;

		grid.clear();

		cin >> col;
		cin >> row;
	}
	

}