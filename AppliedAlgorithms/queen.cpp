#include <iostream>
#include <vector>

using namespace std;

int N, G;
int num = 0;
int col = 0;
int k, x, y, s, t, qx, qy;
vector <int> h, v, ru, lu;

int getCollisions() {

	int n = 0;

	for (int i = 0; i < N; i++) {
		if (v[i] > 1) {
			n += v[i] - 1;
		}
		if (h[i] > 1) {
			n += h[i] - 1;
		}
	}

	for (int c = 0; c < (N * 2 - 1); c++) {
		if (ru[c] > 1) {
			n += ru[c] - 1;
		}
		if (lu[c] > 1) {
			n += lu[c] - 1;
		}
	}

	return n;

}

void addQueens() {

	for (int i = 0; i < k; i++) {
		qx = x + i * s - 1;
		qy = y + i * t - 1;
		h.at(qx)++;
		v.at(qy)++;
		ru.at(qy - qx + N - 1)++;
		lu.at(qy + qx)++;
	}
}

void getQueens() {

	cin >> k >> x >> y >> s >> t;

}

void getInput() {

	cin >> N;

	if (N != 0) {
		cin >> G;
	}

}

vector <int> createSimpleVector() {

	vector<int> vect(N);

	return vect;

}

vector <int> createVector() {

	vector<int> vect(N * 2 - 1);

	return vect;

}

int main() {

	getInput();

	h = createSimpleVector();
	v = createSimpleVector();
	ru = createVector();
	lu = createVector();


	while (N != 0) {

		while (num < G) {
			getQueens();
			addQueens();
			num++;
		}

		col = getCollisions();

		cout << col << endl;

		col = 0;
		num = 0;


		getInput();

		
		if (N != 0) {

			h.clear();
			v.clear();
			ru.clear();
			lu.clear();

			h = createVector();
			v = createVector();
			ru = createVector();
			lu = createVector();

		}
		
	}

}