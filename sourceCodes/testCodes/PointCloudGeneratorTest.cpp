#include "FileReader.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudInterface.h"





int main() {

	PointCloud camera1PC , camera2PC , result;

	FilterPipe filterPipe;
	filterPipe.addFilter(new RadiusOutlierFilter(25));
	filterPipe.addFilter(new PassThroughFilter(400, 0, 400, 0, 45, -45));

	Transform t1;
	Eigen::Vector3d rotation = { 0,0,-90 }; // D�n���m matrisi olu�turmak i�in.
	Eigen::Vector3d translation = { 100,500,50 }; // �ki koordinat sistemi aras�ndaki uzakl�k.

	string filePath = "camera1.txt";
	DepthCamera camera1(filePath);
	camera1.setFilterPipe(filterPipe);
	camera1.setTransform(t1, rotation, translation);


	FilterPipe filterPipe2;
	filterPipe2.addFilter(new RadiusOutlierFilter(25));
	filterPipe2.addFilter(new PassThroughFilter(500, 0, 500, 0, 45, -45));

	Transform t2;
	rotation = { 0,0,90 }; // D�n���m matrisi olu�turmak i�in.
	translation = { 550,50,50 }; // �ki koordinat sistemi aras�ndaki uzakl�k.

	filePath = "camera2.txt";
	DepthCamera camera2(filePath);
	camera2.setFilterPipe(filterPipe2);
	camera2.setTransform(t2, rotation, translation);

	camera1PC = camera1.captureFor();
	camera2PC = camera2.captureFor();

	result = camera1PC + camera2PC;

	PointCloudRecorder pointCloudRecorder;
	string name = "clearedShapeTestForGenerator.txt";
	pointCloudRecorder.setfileName(name);
	pointCloudRecorder.save(result);
	pointCloudRecorder.close();


	return 0;
}