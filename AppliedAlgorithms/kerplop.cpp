#include <iostream>
#include <vector>

using namespace std;

int checkLetter(char l) {
	int temp;

	if (l == 'a') {
		temp = 0;
	}
	else if (l == 'b') {
		temp = 1;
	}
	else if (l == 'c') {
		temp = 2;
	}
	else if (l == 'd') {
		temp = 3;
	}
	else if (l == 'e') {
		temp = 4;
	}
	else if (l == 'f') {
		temp = 5;
	}
	else if (l == 'g') {
		temp = 6;
	}
	else if (l == 'h') {
		temp = 7;
	}
	else if (l == 'i') {
		temp = 8;
	}
	else if (l == 'j') {
		temp = 9;
	}

	return temp;
}

void updateBoard(char b[][10]) {
	
	int j;

	for (int y = 0; y < 10; y++) {
		j = 0;

		for (int x = 0; x < 12; x++) {
			if (b[x][y] != '*') {
				swap(b[j][y], b[x][y]);
				j++;
			}
		}

	}

	bool empty, e;

	
	for (int y = 0; y < 10; y++) {
		empty = true;

		for (int x = 0; x < 12; x++) {
			if (b[x][y] != '*') {
				empty = false;
			}
		}
		if (empty == true) {

			for (int col = y + 1; col < 10; col++) {
				e = true;

				for (int row = 0; row < 12; row++) {

					if (b[row][col] != '*') {
						e = false;
					}
				}
				if (e == false) {
					
					for (int o = 0; o < 12; o++) {

						swap(b[o][y], b[o][col]);
						
					}
					break;
				}

			}
		}

	}
	
}

int checkCluster(char b[][10], int r, int c, char prevC, char newC) {
	int count = 0;

	if (r < 0 || r >= 12 || c < 0 || c >= 10)
		return 0;

	if (r > 0 || r < 11 || c > 0 || c < 9) {
		if (b[r + 1][c] == prevC) {
			count++;
		}
		if (b[r - 1][c] == prevC) {
			//count += checkCluster(b, r - 1, c, prevC, newC);
			count++;
		}
		if (b[r][c - 1] == prevC) {
			count++;
		}
		if (b[r][c + 1] == prevC) {
			count++;
		}
	}
	if (r < 11 || c > 0 || c < 9) {
		if (b[r + 1][c] == prevC) {
			count++;
		}
		if (b[r][c - 1] == prevC) {
			count++;
		}
		if (b[r][c + 1] == prevC) {
			count++;
		}
	}
	if (r > 0 || c > 0 || c < 9) {
		if (b[r - 1][c] == prevC) {
			//count += checkCluster(b, r - 1, c, prevC, newC);
			count++;
		}
		if (b[r][c - 1] == prevC) {
			count++;
		}
		if (b[r][c + 1] == prevC) {
			count++;
		}
	}
	if (r > 0 || r < 11 || c < 9) {
		if (b[r + 1][c] == prevC) {
			count++;
		}
		if (b[r - 1][c] == prevC) {
			//count += checkCluster(b, r - 1, c, prevC, newC);
			count++;
		}
		if (b[r][c + 1] == prevC) {
			count++;
		}
	}
	if (r > 0 || r < 11 || c > 0) {
		if (b[r + 1][c] == prevC) {
			count++;
		}
		if (b[r - 1][c] == prevC) {
			//count += checkCluster(b, r - 1, c, prevC, newC);
			count++;
		}
		if (b[r][c - 1] == prevC) {
			count++;
		}
	}
	

	return count;
}

void fillBoard(char b[][10], int r, int c, char prevC, char newC) {
	int total;

	if (r < 0 || r >= 12 || c < 0 || c >= 10)
		return;
	if (b[r][c] != prevC)
		return;
	if (b[r][c] == newC)
		return;

	total = checkCluster(b, r, c, prevC, newC);

	if (total > 2) {
		b[r][c] = newC;

		fillBoard(b, r + 1, c, prevC, newC);
		fillBoard(b, r - 1, c, prevC, newC);
		fillBoard(b, r, c + 1, prevC, newC);
		fillBoard(b, r, c - 1, prevC, newC);
	}
	
}

int countBoard(char b[][10]) {
	int count = 0;

	for (int x = 0; x < 12; x++) {
		for (int y = 0; y < 10; y++) {
			if (b[x][y] != '*') {
				count++;
			}
		}
	}

	return count;
}

void solveKerplop(char b[][10], int r, int c, char newC) {

	char prevC = b[r][c];

	if (prevC == newC) {
		return;
	}

	fillBoard(b, r, c, prevC, newC);

}

int main() {
	int T, count, row, col, total;
	string temp;
	char letter, newC = '*';
	char board[12][10];

	cin >> T;

	while (T != 0) {

		for (int i = 11; i >= 0; i--) {

			cin >> temp;
			count = 0;

			for (int j = 0; j < 10; j++) {

				board[i][j] = temp[count];
				count++;

			}
		}
		
		for (int x = 0; x < T; x++) {
			cin >> letter;
			cin >> row;
			col = checkLetter(letter);
			row -= 1;

			solveKerplop(board, row, col, newC);
			updateBoard(board);
		}

		total = countBoard(board);
		
		
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 10; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		

		cout << total << endl;

		cin >> T;
	}
	
}