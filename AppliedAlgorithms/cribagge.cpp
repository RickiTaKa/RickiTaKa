#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct cartas {
	char valor;
	char palo;
};

int parejas(vector<cartas> mano) {

	int parejas = 0;
	int count = 0;

	vector<int> pairs;

	for (auto& i : mano) {

		if (i.valor == 65) {
			pairs.push_back(1);
		}
		else if (i.valor == 84) {
			pairs.push_back(10);
		}
		else if (i.valor == 74) {
			pairs.push_back(11);
		}
		else if (i.valor == 81) {
			pairs.push_back(12);
		}
		else if (i.valor == 75) {
			pairs.push_back(13);
		}
		else {
			pairs.push_back(i.valor);
		}
	}

	sort(pairs.begin(), pairs.end());

	for (int card = 1; card < 14; card++) {

		for (auto i : pairs) {

			if (i == card) {
				count++;
			}
		}

		if (count > 1) {

			if (count == 2) {
				parejas += 2;
			}
			else if (count == 3) {
				parejas += 6;
			}
			else if (count == 4) {
				parejas += 12;
			}
			else if (count == 5) {
				parejas += 8;
			}
		}

		count = 0;
	}

	return (parejas);
}

int escalera(vector<cartas> mano) {

	vector<int> cartas;

	int escaleras = 1;
	int num = 1;
	int c = 0;
	int check = 0;

	bool fin = true;

	for (auto& i : mano) {

		if (i.valor == 65) {
			cartas.push_back(1);
		}
		else if (i.valor == 84) {
			cartas.push_back(10);
		}
		else if (i.valor == 74) {
			cartas.push_back(11);
		}
		else if (i.valor == 81) {
			cartas.push_back(12);
		}
		else if (i.valor == 75) {
			cartas.push_back(13);
		}
		else {
			cartas.push_back(i.valor);
		}
	}

	sort(cartas.begin(), cartas.end());

	for (int card = 0; card < mano.size(); card++) {

		if (card != mano.size() - 1 && cartas[card] == cartas[card + 1]) {

			if (card == mano.size() - 2 && cartas[mano.size() - 2] == cartas[mano.size() - 1] && fin) {
				c += 2;
				fin = false;
			}
			else {
				c += 2;
			}
		}
		else {

			if (card == 1 && cartas[card + 1] != cartas[card] + 1) {
				c = 1;
			}

			if (card != mano.size() - 1 && cartas[card + 1] == cartas[card] + 1) {
				num++;
			}
			else if (card != mano.size() - 1 && cartas[card + 1] != cartas[card] + 1) {
				num = 1;
			}

			if (num > 2) {
				escaleras = num;
			}
		}
	}

	for (int i = 0; i < 3; i++) {

		if (i != cartas.size() - 1 && cartas[i] == cartas[i + 2]) {
			check++;
		}
	}

	if (check == 1 && escaleras > 2) {
		return escaleras * 3;
	}

	if (c > 0 && escaleras > 2) {
		return escaleras * c;
	}
	else if (escaleras > 2) {
		return escaleras;
	}
	else {
		return 0;
	}

}

int sums(vector<cartas> mano) {

	int t = 0;
	int num = 0;
	int val;

	for (auto& i : mano) {

		val = i.valor;

		if (val == 65) {
			num++;
			i.valor = 1;
		}
		else if (val == 84 || val == 74 || val == 81 || val == 75) {
			num += 10;
			i.valor = 10;
		}
		else {
			num += i.valor;
		}
	
	}

	if (num == 15) {
		t += 2;
	}
	else {
		t += 0;
	}

	for (int i = 0; i < mano.size(); i++) {

		for (int c = i + 1; c < mano.size(); c++) {

			if (mano[i].valor + mano[c].valor == 15) {
				t += 2;
			}
		}
	}

	for (int i = 0; i < mano.size(); i++) {

		for (int c = i + 1; c < mano.size(); c++) {

			for (int y = c + 1; y < mano.size(); y++) {

				if (mano[i].valor + mano[c].valor + mano[y].valor == 15) {
					t += 2;
				}
					
			}
		}
	}

	for (int i = 0; i < 2; i++) {

		if (i == 0) {

			if (mano[i].valor + mano[i + 2].valor + mano[i + 3].valor + mano[i + 4].valor == 15) {
				t += 2;
			}
			if (mano[i].valor + mano[i + 1].valor + mano[i + 3].valor + mano[i + 4].valor == 15) {
				t += 2;
			}
			if (mano[i].valor + mano[i + 1].valor + mano[i + 2].valor + mano[i + 4].valor == 15) {
				t += 2;
			}
			if (mano[i].valor + mano[i + 1].valor + mano[i + 2].valor + mano[i + 3].valor == 15) {
				t += 2;
			}
				
		}
		else if (i == 1) {

			if (mano[i].valor + mano[i + 1].valor + mano[i + 2].valor + mano[i + 3].valor == 15) {
				t += 2;
			}
		}
		
	}

	return t;
}

int color(vector<cartas> mano) {

	int sum = 0;

	if (mano[0].palo == mano[1].palo && mano[1].palo == mano[2].palo && mano[2].palo == mano[3].palo && mano[3].palo == mano[4].palo) {
		sum = 5;
		return sum;
	}
	else if (mano[0].palo == mano[1].palo && mano[1].palo == mano[2].palo && mano[2].palo == mano[3].palo) {
		sum = 4;
		return sum;
	}
	else {
		return sum;
	}

}

int jota(vector<cartas> mano) {

	for (int i = 0; i < 4; i++) {

		if (mano[i].palo == mano[4].palo && mano[i].valor == 'J') {
			return 1;
		}
	}

	return 0;
}

void result(vector<cartas> mano) {

	int t = 0;

	t += parejas(mano);
	t += escalera(mano);
	t += sums(mano);
	t += color(mano);
	t += jota(mano);

	cout << t << endl;
}

int main() {

	string c;
	cin >> c;

	vector<cartas> cards(5);

	while (c != "0") {

		for (int i = 0; i < 5; i++) {

			if (c[0] == 'A' || c[0] == 'T' || c[0] == 'J' || c[0] == 'Q' || c[0] == 'K') {
				cards[i].valor = c[0];
			}
				
			else {
				cards[i].valor = c[0] - '0';
			}
				
			cards[i].palo = c[1];

			if (i != 4) {
				cin >> c;
			}
		}

		result(cards);
		cards.empty();

		cin >> c;
	}
}