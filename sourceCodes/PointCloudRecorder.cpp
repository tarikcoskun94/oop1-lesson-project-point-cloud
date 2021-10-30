#include"PointCloudRecorder.h"
/**
* \brief <h2><b><i>Constructur.</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametrelere gore yapilan constructor.</p>
*
* \param fileName: fileName degiskeni.
*
*/
PointCloudRecorder::PointCloudRecorder(string& fileName) {

	setfileName(fileName);

}
/**
* \brief <h2><b><i>setfileName fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;fileName degiskenine deger atar.</p>
*
* \param fileName: fileName degiskeni.
*
*/
void PointCloudRecorder::setfileName(string& fileName) {
	if (myfile.is_open()) {
		myfile.close();
	}

	this->fileName = fileName;
	myfile.open(fileName, ios::app);

	try {
		if (!myfile.is_open()) {
			throw errorWriteFile();
		}
	}
	catch (errorWriteFile error) {
		error.message(fileName);
	}
}
/**
* \brief <h2><b><i>getfileName fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;fileName degiskenini dondurur</p>
*
* \return fileName
*/
string PointCloudRecorder::getfileName() {

	return fileName;

}
/**
* \brief <h2><b><i>save fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp; icine PointCloud tipinde obje alip , gelen nokta bulutlarini line line dosyaya aktarma fonksiyonu.</p>
*
* \param pc: 
* \return true/false
*/
bool PointCloudRecorder::save(const PointCloud& pc) {

	list <Point> PointLIST = pc.getPoints();

	list <Point>::iterator it;

	for (it = PointLIST.begin(); it != PointLIST.end(); it++)
	{
		try {
			myfile << it->getX() << "  " << it->getY() << "  " << it->getZ() << endl;
			if (myfile.fail()) {
				throw errorWriteLine();
			}
		}
		catch (errorWriteLine error) {
			error.message();
			myfile.clear();
			return false;
		}
	}

	return true;
}

/**
* \brief <h2><b><i>Dosya kapatma fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Acilmis olan dosyayi kapatir.</p>
*
*/
void PointCloudRecorder::close() {
	myfile.close();
}
