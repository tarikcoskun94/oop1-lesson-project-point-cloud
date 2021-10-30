#include "DepthCamera.h"



/**
* \brief <h2><b><i>Parametre ile default Constructor</i></b></h2>
*
* <p>&emsp;&emsp;Nesne yaratilirken dosya ismini alir.</p>
*
* \param fileName: Dosya ismi
*/
DepthCamera::DepthCamera(const string& fileName){

	this->fileName = fileName;
}

/**
* \brief <h2><b><i>fileName icin getter</i></b></h2>
*
* <p>&emsp;&emsp;fileName degerini dondurur.</p>
*
* \return fileName
*/
string DepthCamera::getFileName() const {
	return fileName;
}

/**
* \brief <h2><b><i>fileName icin setter</i></b></h2>
*
* <p>&emsp;&emsp;fileName degerini set eder.</p>
*
* \param fileName: Dosya ismi
*/
void DepthCamera::setFileName(string& fileName) {
	this->fileName = fileName;
}


/**
* \brief <h2><b><i>Dosyadaki noktalari algilar</i></b></h2>
*
* <p>&emsp;&emsp;Dosya okuma sinifi ile dosyayi satir satir okur ve uygun sekilde nokta bulutunu yaratip dondurur.</p>
*
* \return pointCloudTMP
*/
PointCloud DepthCamera::capture() {
	try {
		//int pointCount = 0;
		Point pointTMP;
		list <Point> pointLIST;



		FileReader camReader(fileName);



		while (!camReader.endOfFile()) {
			istringstream iss(camReader.readLine());

			string x, y, z;
			if (!(iss >> x >> y >> z)) { // satýrlar parse ediliyor ve check ediliyor.
				throw errorLineFormat();
			}

			pointTMP.setX(stoi(x));
			pointTMP.setY(stoi(y));
			pointTMP.setZ(stoi(z));

			pointLIST.push_back(pointTMP);
		}



		PointCloud pointCloudTMP;
		pointCloudTMP.setPoints(pointLIST);



		return pointCloudTMP;
	}
	catch (errorLineFormat error) {
		error.message();
	}
}


/**
* \brief <h2><b><i>Dosyadaki noktalari algilar</i></b></h2>
*
* <p>&emsp;&emsp;Dosya okuma sinifi ile dosyayi satir satir okur ve uygun sekilde nokta bulutunu yaratip dondurur.</p>
*
* \return pointCloudTMP
*/
PointCloud DepthCamera::captureFor() {
	PointCloud pcTMP = this->capture();

	filterPipe.filterOut(pcTMP);
	
	pcTMP = transform.doTransform(pcTMP); // pcTMP için dönüþüm baþlar.


	return pcTMP;
}