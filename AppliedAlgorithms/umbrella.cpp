#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float findDistance(float x1, float y1, float x2, float y2) {
	float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.000);
	if (d < 0) {
		d *= -1.000;
		return d;
	}
	else {
		return d;
	}
}

void solveProblem(vector<float> x, vector<float> y, int u) {

	float total = 0.000;

	for (int i = 0; i < u; i++) {
		if (i != (u - 1)) {
			total += findDistance(x[i], y[i], x[i + 1], y[i + 1]);
		}
		else {
			total += findDistance(x[i], y[i], x[0], y[0]);
		}
	}

	cout << total << endl;
}

int main() {
	vector<float> x, y;
	int umbrellas;
	float tempx, tempy;

	cin >> umbrellas;

	while (umbrellas != 0) {

		for (int i = 0; i < umbrellas; i++) {
			cin >> tempx;
			cin >> tempy;

			x.push_back(tempx);
			y.push_back(tempy);
		}

		solveProblem(x, y, umbrellas);

		x.clear();
		y.clear();
		cin >> umbrellas;
	}

}