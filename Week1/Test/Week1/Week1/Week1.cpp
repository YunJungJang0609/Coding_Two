// Week1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <time.h>
#include "Source.h"

using namespace std;


int main(int x, int y, int z) {

	while (true) {

		srand((int)time(NULL));
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;
		int mySum(int x, int y);

		cout << x << " + " << y << " = ?" << endl;

		cin >> z;

		int result = mySum(x, y);

		if (z == result) {
			cout << "Correct! \n\n";
		}
		else {
			cout << "Wrong! Try again. \n\n";
		}
	}
	return 0;
}
