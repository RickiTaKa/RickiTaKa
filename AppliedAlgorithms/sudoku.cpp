#include <iostream>

using namespace std;

void printGrid(int g[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int c = 0; c < 9; c++) {
			cout << g[i][c];
			if (c != 8) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool check(int g[9][9], int r, int c, int n)
{

	for (int i = 0; i <= 8; i++) {
		if (g[r][i] == n) {
			return false;
		}
	}
	
	for (int y = 0; y <= 8; y++) {
		if (g[y][c] == n) {
			return false;
		}
	}

	int row = r - r % 3, col = c - c % 3;

	for (int j = 0; j < 3; j++) {
		for (int x = 0; x < 3; x++) {
			if (g[j + row][x + col] == n) {
				return false;
			}
		}
	}

	return true;
}

bool solve(int g[9][9], int r, int c)
{
	
	if (r == 8 && c == 9) {
		return true;
	}

	if (c == 9) {
		r++;
		c = 0;
	}

	if (g[r][c] > 0) {
		return solve(g, r, c + 1);
	}

	for (int num = 1; num <= 9; num++) {

		if (check(g, r, c, num)) {

			g[r][c] = num;

			if (solve(g, r, c + 1)) {
				return true;
			}
		}

		g[r][c] = 0;
	}

	return false;
}

int main() {
	int grid[9][9];
	int test, num;

	cin >> test;

	while (test != 0) {

		for (int i = 0; i < 9; i++) {
			for (int c = 0; c < 9; c++) {
				cin >> num;
				grid[i][c] = num;
			}
		}
		cout << "Test Case #" << test << ":" << endl;
		if (solve(grid, 0, 0)) {
			printGrid(grid);
		}
		else {
			cout << "No solution" << endl << endl;
		}

		cin >> test;
	}
	
}
