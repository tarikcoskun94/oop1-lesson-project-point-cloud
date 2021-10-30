#include <iostream>
#include"Transform.h"

using namespace std;





int main() {

	list <Point> pointsA;

	Point pointTMP;

	
	pointTMP.setX(0);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);


	pointTMP.setX(10);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);

	
	pointTMP.setX(20);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);

	
	pointTMP.setX(500);
	pointTMP.setY(550);
	pointTMP.setZ(560);
	pointsA.push_back(pointTMP);


	pointTMP.setX(40);
	pointTMP.setY(15);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);

	
	pointTMP.setX(40);
	pointTMP.setY(15);
	pointTMP.setZ(23);
	pointsA.push_back(pointTMP);

	
	pointTMP.setX(350);
	pointTMP.setY(-600);
	pointTMP.setZ(90);
	pointsA.push_back(pointTMP);


	pointTMP.setX(-10);
	pointTMP.setY(0);
	pointTMP.setZ(0);
	pointsA.push_back(pointTMP);


	pointTMP.setX(40);
	pointTMP.setY(15);
	pointTMP.setZ(43);
	pointsA.push_back(pointTMP);


	PointCloud newPointCloud;
	newPointCloud.setPoints(pointsA);


	Eigen::Vector3d anglesTest = { 0,0,90 };
	Eigen::Vector3d transTest = { 450,350,0 };
	Transform transformTest;

	transformTest.setRotation(anglesTest);
	transformTest.setTranslation(transTest);
	
	newPointCloud = transformTest.doTransform(newPointCloud);

	cout << "getPoints after transform" << endl;
	list <Point> pointsLIST = newPointCloud.getPoints();

	list <Point>::iterator it;
	for (it = pointsLIST.begin(); it != pointsLIST.end(); it++) {
		cout << it->getX() << " - ";
		cout << it->getY() << " - ";
		cout << it->getZ() << endl;
	}
	cout << endl;



	system("Pause");
	return 0;
}