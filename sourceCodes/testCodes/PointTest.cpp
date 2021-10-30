#include <iostream>
#include "Point.h"


using namespace std;





int main() {

	Point TEST1;
	TEST1.setX(26);
	TEST1.setY(-98);
	TEST1.setZ(650);

	Point TEST2;
	TEST2.setX(0);
	TEST2.setY(87);
	TEST2.setZ(-250);

	Point TEST3;
	TEST3.setX(0);
	TEST3.setY(87);
	TEST3.setZ(-250);


	cout << "TEST1 | (x, y, z) | " << TEST1.getX() << " - " << TEST1.getY() << " - " << TEST1.getZ() << endl;
	cout << "TEST2 | (x, y, z) | " << TEST2.getX() << " - " << TEST2.getY() << " - " << TEST2.getZ() << endl;
	cout << "TEST3 | (x, y, z) | " << TEST3.getX() << " - " << TEST3.getY() << " - " << TEST3.getZ() << endl;

	cout << endl << endl;

	cout << "Distance TEST1 - TEST2: " << TEST1.distance(TEST2) << endl;
	cout << "Distance TEST2 - TEST3: " << TEST2.distance(TEST3) << endl;

	cout << endl << endl;

	cout << "Equal TEST1 - TEST2: " << (TEST1 == TEST2) << endl;
	cout << "Equal TEST2 - TEST3: " << (TEST2 == TEST3) << endl;

	system("pause");
	return 0;
}