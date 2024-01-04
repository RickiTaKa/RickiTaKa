#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;


void brokenClock(string numbers) {


	if (numbers == "1") {
		cout << " {1,7} {4,9}" << endl;
	}
	else if (numbers == "12") {
		cout << " {1,7} {4,9}" << endl;
	}
	else if (numbers == "123") {
		cout << " {1,7} {3,5} {4,9} {6,8}" << endl;
	}
	else if (numbers == "1234") {
		cout << " {0,6,8} {1,4,7,9} {3,5}" << endl;
	}
	else if (numbers == "12345") {
		cout << " {0,3,5,6,8} {1,4,7,9}" << endl;
	}
	else if (numbers == "123456") {
		cout << " {0,2,3,5,6,8} {1,4,7,9}" << endl;
	}
	else if (numbers == "1234567") {
		cout << " {0,1,2,3,4,5,6,7}" << endl;
	}
	else if (numbers == "12346") {
		cout << " {0,2,6,8} {1,4,7,9} {3,5}" << endl;
	}
	else if (numbers == "124") {
		cout << " {0,8} {1,4,7,9}" << endl;
	}
	else if (numbers == "1245") {
		cout << " {0,3,8} {1,4,7,9} {5,6}" << endl;
	}
	else if (numbers == "12456") {
		cout << " {0,2,3,8} {1,4,7,9} {5,6}" << endl;
	}
	else if (numbers == "124567") {
		cout << " {0,1,2,3,4,7,8,9} {5,6}" << endl;
	}
	else if (numbers == "125") {
		cout << " {1,7} {3,8} {4,9} {5,6}" << endl;
	}
	else if (numbers == "1256") {
		cout << " {1,7} {2,3,8} {4,9} {5,6}" << endl;
	}
	else if (numbers == "12567") {
		cout << " {0,1,7} {2,3,4,8,9} {5,6}" << endl;
	}
	else if (numbers == "126") {
		cout << " {1,7} {2,8} {3,4,9}" << endl;
	}
	else if (numbers == "1267") {
		cout << " {1,7} {2,8} {3,4,9}" << endl;
	}
	else if (numbers == "13") {
		cout << " {1,7} {4,9} {6,8}" << endl;
	}
	else if (numbers == "134") {
		cout << " {0,6,8} {1,7} {4,9}" << endl;
	}
	else if (numbers == "1345") {
		cout << " {0,5,6,8} {1,7} {4,9}" << endl;
	}
	else if (numbers == "13456") {
		cout << " {0,5,6,8} {1,7} {2,3} {4,9}" << endl;
	}
	else if (numbers == "134567") {
		cout << " {0,4,5,6,8,9} {1,2,3,7}" << endl;
	}
	else if (numbers == "135") {
		cout << " {1,7} {4,9} {5,6,8}" << endl;
	}
	else if (numbers == "1356") {
		cout << " {1,7} {2,3} {4,9} {5,6,8}" << endl;
	}
	else if (numbers == "13567") {
		cout << " {1,7} {2,3} {4,5,6,8,9}" << endl;
	}
	else if (numbers == "136") {
		cout << " {1,7} {4,9} {6,8}" << endl;
	}
	else if (numbers == "1367") {
		cout << " {1,7} {4,5,9} {6,8}" << endl;
	}
	else if (numbers == "137") {
		cout << " {1,7} {4,5,9} {6,8}" << endl;
	}
	else if (numbers == "14") {
		cout << " {0,8} {1,7} {4,9}" << endl;
	}
	else if (numbers == "145") {
		cout << " {0,8} {1,7} {4,9} {5,6}" << endl;
	}
	else if (numbers == "1456") {
		cout << " {0,8} {1,7} {2,3} {4,9} {5,6}" << endl;
	}
	else if (numbers == "14567") {
		cout << " {0,4,8,9} {1,2,3,7} {5,6}" << endl;
	}
	else if (numbers == "146") {
		cout << " {0,8} {1,7} {4,9}" << endl;
	}
	else if (numbers == "1467") {
		cout << " {0,8} {1,3,7} {4,9}" << endl;
	}
	else if (numbers == "147") {
		cout << " {0,8} {1,7} {4,9}" << endl;
	}
	else if (numbers == "15") {
		cout << " {1,7} {4,9} {5,6}" << endl;
	}
	else if (numbers == "156") {
		cout << " {1,7} {2,3} {4,9} {5,6}" << endl;
	}
	else if (numbers == "1567") {
		cout << " {1,7} {2,3} {4,8,9} {5,6}" << endl;
	}
	else if (numbers == "157") {
		cout << " {1,7} {4,8,9} {5,6}" << endl;
	}
	else if (numbers == "16") {
		cout << " {1,7} {4,9}" << endl;
	}
	else if (numbers == "167") {
		cout << " {1,7} {4,9}" << endl;
	}
	else if (numbers == "17") {
		cout << " {1,7} {4,9}" << endl;
	}
	else if (numbers == "2") {
		cout << endl;
	}
	else if (numbers == "23") {
		cout << " {6,8} {3,5}" << endl;
	}
	else if (numbers == "234") {
		cout << " {0,6,8} {1,4} {3,5} {7,9}" << endl;
	}
	else if (numbers == "2345") {
		cout << " {0,3,5,6,8} {1,4} {7,9}" << endl;
	}
	else if (numbers == "23456") {
		cout << " {0,2,3,5,6,8} {1,4} {7,9}" << endl;
	}
	else if (numbers == "234567") {
		cout << " {0,2,3,5,6,7,8,9} {1,4}" << endl;
	}
	else if (numbers == "235") {
		cout << " {3,5,6,8}" << endl;
	}
	else if (numbers == "2356") {
		cout << " {2,3,5,6,8}" << endl;
	}
	else if (numbers == "23567") {
		cout << " {0,7} {2,3,5,6,8,9}" << endl;
	}
	else if (numbers == "236") {
		cout << " {2,6,8} {3,5}" << endl;
	}
	else if (numbers == "2367") {
		cout << " {2,6,8} {3,5,9}" << endl;
	}
	else if (numbers == "237") {
		cout << " {3,5,9} {6,8}" << endl;
	}
	else if (numbers == "24") {
		cout << " {0,8} {1,4} {7,9}" << endl;
	}
	else if (numbers == "245") {
		cout << " {0,3,8} {1,4} {5,6} {7,9}" << endl;
	}
	else if (numbers == "2456") {
		cout << " {0,2,3,8} {1,4} {5,6} {7,9}" << endl;
	}
	else if (numbers == "24567") {
		cout << " {0,2,3,7,8,9} {1,4} {5,6}" << endl;
	}
	else if (numbers == "246") {
		cout << " {0,2,8} {1,4} {7,9}" << endl;
	}
	else if (numbers == "2467") {
		cout << " {0,2,8} {1,4} {3,7,9}" << endl;
	}
	else if (numbers == "247") {
		cout << " {0,8} {1,4} {3,7,9}" << endl;
	}
	else if (numbers == "25") {
		cout << " {3,8} {5,6}" << endl;
	}
	else if (numbers == "256") {
		cout << " {2,3,8} {5,6}" << endl;
	}
	else if (numbers == "2567") {
		cout << " {2,3,8,9} {5,6}" << endl;
	}
	else if (numbers == "257") {
		cout << " {0,7} {3,8,9} {5,6}" << endl;
	}
	else if (numbers == "26") {
		cout << " {2,8}" << endl;
	}
	else if (numbers == "267") {
		cout << " {2,8}" << endl;
	}
	else if (numbers == "27") {
		cout << endl;
	}
	else if (numbers == "3") {
		cout << " {6,8}" << endl;
	}
	else if (numbers == "34") {
		cout << " {0,6,8}" << endl;
	}
	else if (numbers == "345") {
		cout << " {0,5,6,8}" << endl;
	}
	else if (numbers == "3456") {
		cout << " {0,5,6,8} {2,3}" << endl;
	}
	else if (numbers == "34567") {
		cout << " {0,5,6,8,9} {2,3,7}" << endl;
	}
	else if (numbers == "3457") {
		cout << " {0,5,6,8,9} {3,7}" << endl;
	}
	else if (numbers == "346") {
		cout << " {0,6,8}" << endl;
	}
	else if (numbers == "3467") {
		cout << " {0,6,8} {2,3} {3,7} {5,9}" << endl;
	}
	else if (numbers == "347") {
		cout << " {0,6,8} {3,7} {5,9}" << endl;
	}
	else if (numbers == "35") {
		cout << " {5,6,8}" << endl;
	}
	else if (numbers == "356") {
		cout << " {2,3} {5,6,8}" << endl;
	}
	else if (numbers == "3567") {
		cout << " {2,3} {5,6,8,9}" << endl;
	}
	else if (numbers == "357") {
		cout << " {5,6,8,9}" << endl;
	}
	else if (numbers == "36") {
		cout << " {6,8}" << endl;
	}
	else if (numbers == "367") {
		cout << " {6,8}" << endl;
	}
	else if (numbers == "37") {
		cout << " {6,8}" << endl;
	}
	else if (numbers == "4") {
		cout << " {0,8}" << endl;
	}
	else if (numbers == "45") {
		cout << " {0,8} {5,6}" << endl;
	}
	else if (numbers == "456") {
		cout << " {0,8} {2,3} {5,6}" << endl;
	}
	else if (numbers == "4567") {
		cout << " {0,8,9} {2,3} {5,6}" << endl;
	}
	else if (numbers == "46") {
		cout << " {0,8}" << endl;
	}
	else if (numbers == "467") {
		cout << " {0,8} {3,7}" << endl;
	}
	else if (numbers == "47") {
		cout << " {0,8}" << endl;
	}
	else if (numbers == "5") {
		cout << " {5,6}" << endl;
	}
	else if (numbers == "56") {
		cout << " {2,3} {5,6}" << endl;
	}
	else if (numbers == "567") {
		cout << " {2,3} {5,6} {8,9}" << endl;
	}
	else if (numbers == "57") {
		cout << " {5,6} {8,9}" << endl;
	}
	else if (numbers == "6") {
		cout << endl;
	}
	else if (numbers == "67") {
		cout << endl;
	}
	else if (numbers == "7") {
		cout << endl;
	}
	else {
		cout << endl;
	}

}

int main() {

	int led;
	cin >> led;
	bitset<7> convertedLed;
	string numbers;

	while (led != 0) {

		numbers = to_string(led);

		cout << "Case <" << led;

		while (led != 0) {
			cin >> led;
			if (led != 0) {
				cout << "," << led;
				numbers += to_string(led);
			}
		}

		cout << ">:";

		brokenClock(numbers);

		cin >> led;

	}

}