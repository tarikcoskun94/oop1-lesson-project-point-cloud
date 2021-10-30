#include <iostream>
#include"RadiusOutlierFilter.h"

using namespace std;





int main() {
	list <Point> pointsA;

	Point pointTMP;


	//Gecmesi gereken degerler
	pointTMP.setX(0);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(10);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(20);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler z yuzunden
	pointTMP.setX(500);
	pointTMP.setY(550);
	pointTMP.setZ(560);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(40);
	pointTMP.setY(15);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(40);
	pointTMP.setY(15);
	pointTMP.setZ(23);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler y ve z yuzunden
	pointTMP.setX(350);
	pointTMP.setY(-600);
	pointTMP.setZ(90);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(-10);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(40);
	pointTMP.setY(15);
	pointTMP.setZ(43);
	pointsA.push_back(pointTMP);

	PointCloud newPointCloud;
	newPointCloud.setPoints(pointsA);
	


	RadiusOutlierFilter radiusFilterTest(25);
	
	radiusFilterTest.filter(newPointCloud);
	
	list <Point> pointsLIST = newPointCloud.getPoints();

	list <Point>::iterator it;
	for (it = pointsLIST.begin(); it != pointsLIST.end(); it++) {
		cout << it->getX() << " - ";
		cout << it->getY() << " - ";
		cout << it->getZ() << endl;
	}





	system("Pause");
	return 0;
}