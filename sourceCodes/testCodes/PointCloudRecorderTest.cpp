#include <iostream>
#include"PointCloudRecorder.h"

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

	string fileName = "PointCloudRecorderTest.txt";
	PointCloudRecorder PointCloudRecorderTest(fileName);

	PointCloudRecorderTest.save(newPointCloud);
	PointCloudRecorderTest.close();

}