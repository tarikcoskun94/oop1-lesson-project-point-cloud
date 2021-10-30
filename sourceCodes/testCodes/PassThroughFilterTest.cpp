#include <iostream>
#include"PassThroughFilter.h"

using namespace std;





int main() {
	list <Point> pointsA;

	Point pointTMP;


	Point* point = new Point[9];
	//Gecmesi gereken degerler
	pointTMP.setX(200);
	pointTMP.setY(200);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler x yuzunden
	pointTMP.setX(-400);
	pointTMP.setY(200);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler y yuzunden 
	pointTMP.setX(200);
	pointTMP.setY(600);
	pointTMP.setZ(20);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler z yuzunden
	pointTMP.setX(150);
	pointTMP.setY(150);
	pointTMP.setZ(60);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler x ve y yuzunden
	pointTMP.setX(500);
	pointTMP.setY(-100);
	pointTMP.setZ(20);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler x ve z yuzunden
	pointTMP.setX(-100);
	pointTMP.setY(100);
	pointTMP.setZ(-90);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler y ve z yuzunden
	pointTMP.setX(350);
	pointTMP.setY(-600);
	pointTMP.setZ(90);
	pointsA.push_back(pointTMP);
	//Gecmemesi gereken degerler x, y ve z yuzunden
	pointTMP.setX(600);
	pointTMP.setY(-600);
	pointTMP.setZ(90);
	pointsA.push_back(pointTMP);
	//Gecmesi gereken degerler
	pointTMP.setX(100);
	pointTMP.setY(350);
	pointTMP.setZ(40);
	pointsA.push_back(pointTMP);

	PointCloud newPointCloud;
	newPointCloud.setPoints(pointsA);



	PassThroughFilter passFilter(400, 0, 400, 0, 45, -45);
	passFilter.filter(newPointCloud); 

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