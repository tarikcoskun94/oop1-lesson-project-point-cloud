#include "PointCloudInterface.h"

/**
* \brief <h2><b><i>addGenerator fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Bu fonksiyon filterlardan ve transform dan gectikten sonra donusturulmus halini generators vectorune ekler.</p>
*
* \param generatedElement: PointCloudGenerator*
*/
void PointCloudInterface::addGenerator(PointCloudGenerator* generatedElement) {

	this->generators.push_back(generatedElement);

}
/**
* \brief <h2><b><i>setRecorder setter fonskiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Private uyesi olan recorder burda set edilir.</p>
*
* \param generatedRecorder: PointCloudRecorder*
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* generatedRecorder) {

	this->recorder = generatedRecorder;

}
/**
* \brief <h2><b><i>generate fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Bu fonksiyon genrators e eklenen donusturulmus ve filtrelerden gecen noktu bulutunu pointCloud private uyesine atar.</p>
*
* \return true/false
*/
bool PointCloudInterface::generate() {

	PointCloud tmpPC;
	int totalSize = 0;

	for (int i = 0; i < generators.size(); i++)
	{
		tmpPC = generators[i]->captureFor();
		pointCloud = pointCloud + tmpPC;
		totalSize += tmpPC.getPoints().size();
		
	}


	if (pointCloud.getPoints().size() == totalSize)
		return true;

	return false;

	
}
/**
* \brief <h2><b><i>record fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;pointCloud uyesi generate fonksiyonuyla beraber son haline geldikten sonra burda dosyaya kaydedilir.</p>
*
* \return true/false
*/
bool PointCloudInterface::record() {


	if (recorder->save(pointCloud)) {
		recorder->close();
		return true;
	}

	return false;
}