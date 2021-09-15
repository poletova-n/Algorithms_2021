#include <iostream>
using namespace std;
int main() {


	int voroni;
	cout << "skolko voron? \n";
	cin >> voroni;


	if (voroni % 10 == 1 and voroni != 11) {
		cout << "V stae " << voroni << " Vorona";
	}
	else if ((voroni % 10 == 2 or voroni % 10 == 3 or voroni % 10 == 4) and voroni != 12 and voroni != 13 and voroni != 14) {
		cout << "V stae " << voroni << " Voroni";
	}
	else {
		cout << "V stae " << voroni << " Voron";
	}	return 0;
}

int pain() {


	int voroni;
	cout << "skolko voron? \n";
	cin >> voroni;


	if (voroni % 10 == 1 and voroni != 11) {
		cout << "V stae " << voroni << " Vorona";
	}
	else if ((voroni % 10 == 2 or voroni % 10 == 3 or voroni % 10 == 4) and voroni != 12 and voroni != 13 and voroni != 14) {
		cout << "V stae " << voroni << " Voroni";
	}
	else {
		cout << "V stae " << voroni << " Voron";
	}	return 0;
}