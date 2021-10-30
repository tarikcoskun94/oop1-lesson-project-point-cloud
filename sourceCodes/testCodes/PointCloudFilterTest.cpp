#include "FileReader.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudInterface.h"





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

	PassThroughFilter passTest(400, 0, 400, 0, 45, -45);
	passTest.filter(newPointCloud);
	RadiusOutlierFilter radiusTest(25);
	radiusTest.filter(newPointCloud);

	PointCloudRecorder pointCloudRecorder;
	string name = "PointCloudFilterTest.txt";
	pointCloudRecorder.setfileName(name);
	pointCloudRecorder.save(newPointCloud);
	pointCloudRecorder.close();

	return 0;
}