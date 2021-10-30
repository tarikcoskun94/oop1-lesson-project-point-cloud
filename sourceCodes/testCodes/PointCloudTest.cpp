#include <iostream>

#include "PointCloud.h"


using namespace std;



int main() {
	list <Point> pointsA;

	Point pointTMP;

	pointTMP.setX(8);
	pointTMP.setY(5);
	pointTMP.setZ(9);
	pointsA.push_back(pointTMP);

	pointTMP.setX(26);
	pointTMP.setY(4);
	pointTMP.setZ(2);
	pointsA.push_back(pointTMP);

	pointTMP.setX(8);
	pointTMP.setY(5);
	pointTMP.setZ(9);
	pointsA.push_back(pointTMP);



	list <Point> pointsB;

	pointTMP.setX(3);
	pointTMP.setY(6);
	pointTMP.setZ(18);
	pointsB.push_back(pointTMP);

	pointTMP.setX(26);
	pointTMP.setY(4);
	pointTMP.setZ(8);
	pointsB.push_back(pointTMP);

	pointTMP.setX(26);
	pointTMP.setY(4);
	pointTMP.setZ(8);
	pointsB.push_back(pointTMP);

	pointTMP.setX(8);
	pointTMP.setY(5);
	pointTMP.setZ(9);
	pointsB.push_back(pointTMP);

	pointTMP.setX(8);
	pointTMP.setY(5);
	pointTMP.setZ(9);
	pointsB.push_back(pointTMP);



	PointCloud newPointCloud1;
	newPointCloud1.setPoints(pointsA);

	system("pause");

	PointCloud newPointCloud2;
	newPointCloud2.setPoints(pointsB);
	system("pause");

	PointCloud newPointCloud3 = newPointCloud1 + newPointCloud2;
	system("pause");

	//newPointCloud3 = newPointCloud2;

	list <Point> pointsLIST = newPointCloud3.getPoints();

	list <Point>::iterator it;
	for (it = pointsLIST.begin(); it != pointsLIST.end(); it++) {
		cout << it->getX() << " - ";
		cout << it->getY() << " - ";
		cout << it->getZ() << endl;
	}



	system("pause");
	return 0;
}