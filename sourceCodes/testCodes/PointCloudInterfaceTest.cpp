#include "FileReader.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudInterface.h"





int main() {

	PointCloudInterface Interface;

	FilterPipe filterPipe;
	filterPipe.addFilter(new RadiusOutlierFilter(25));
	filterPipe.addFilter(new PassThroughFilter(400, 0, 400, 0, 45, -45));

	Transform t1;
	Eigen::Vector3d rotation = { 0,0,-90 }; // Dönüþüm matrisi oluþturmak için.
	Eigen::Vector3d translation = { 100,500,50 }; // Ýki koordinat sistemi arasýndaki uzaklýk.

	string filePath = "camera1.txt";
	DepthCamera camera1(filePath);
	camera1.setFilterPipe(filterPipe);
	camera1.setTransform(t1, rotation, translation);
	Interface.addGenerator(&camera1);




	FilterPipe filterPipe2;
	filterPipe2.addFilter(new RadiusOutlierFilter(25));
	filterPipe2.addFilter(new PassThroughFilter(500, 0, 500, 0, 45, -45));

	Transform t2;
	rotation = { 0,0,90 }; // Dönüþüm matrisi oluþturmak için.
	translation = { 550,50,50 }; // Ýki koordinat sistemi arasýndaki uzaklýk.

	filePath = "camera2.txt";
	DepthCamera camera2(filePath);
	camera2.setFilterPipe(filterPipe2);
	camera2.setTransform(t2, rotation, translation);
	Interface.addGenerator(&camera2);

	PointCloudRecorder pointCloudRecorder;
	string name = "InterfaceTest.txt";
	pointCloudRecorder.setfileName(name);
	Interface.setRecorder(&pointCloudRecorder);


	Interface.generate();
	Interface.record();



	system("pause");
	return 0;
}