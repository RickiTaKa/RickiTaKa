#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return d;
}

double moveX(double x1, double y1, double x2, double y2, double range) {

	double d = distance(x1, y1, x2, y2);
	double directionx = (x2 - x1) / d;
	x1 += directionx * range;

	return x1;
}

double moveY(double x1, double y1, double x2, double y2, double range) {

	double d = distance(x1, y1, x2, y2);
	double directiony = (y2 - y1) / d;
	y1 += directiony * range;

	return y1;
}

void solveProblem(double x, double y, vector<double> x1, vector<double> y1, int count, double range) {
	bool found = false;
	double d;

	for (int i = 0; i < x1.size(); i++) {

		double xtemp = x;
		double ytemp = y;

		if (found != true) {

			x = moveX(xtemp, ytemp, x1[i], y1[i], range);
			y = moveY(xtemp, ytemp, x1[i], y1[i], range);

			d = distance(x, y, x1[i], y1[i]);

			if (d <= 1.0 || d == 0) {
				cout << "Firefly " << count << " caught at (" << x1[i] << "," << y1[i] << ")" << endl;
				found = true;
			}
		}
	}

	if (found != true) {
		cout << "Firefly " << count << " not caught" << endl;
	}
}

int main() {
	int count = 0;
	double x, y, temp1, temp2, range;
	vector<double> x1, y1;

	cin >> range;
	cin >> x;
	cin >> y;

	while (range != 0) {
		count++;

		cin >> temp1;
		cin >> temp2;

		while (temp1 != -1 && temp2 != -1) {

			x1.push_back(temp1);
			y1.push_back(temp2);

			cin >> temp1;
			cin >> temp2;
		}

		solveProblem(x, y, x1, y1, count, range);

		x1.clear();
		y1.clear();

		cin >> range;
		cin >> x;
		cin >> y;
	}
}
