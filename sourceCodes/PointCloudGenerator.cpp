#include "PointCloudGenerator.h"

/**
* \brief <h2><b><i>setFilterPipe fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Fonksiyona gelen filterPipe this->filterPipe a atanir.</p>
*
* \param filterPipe: FilterPipe
*/
void PointCloudGenerator::setFilterPipe(FilterPipe filterPipe) {

	this->filterPipe = filterPipe;

}
/**
* \brief <h2><b><i>setTransform fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Transform icin gerekli olan setRotation ve setTranslation fonksiyonlari burda calistirilir.</p>
*
* \param transform: Transform
* \param rotation: Eigen::Vector3d
* \param translation: Eigen::Vector3d
*/
void PointCloudGenerator::setTransform(Transform transform , Eigen::Vector3d rotation , Eigen::Vector3d translation) {

	this->transform = transform;
	this->transform.setRotation(rotation);
	this->transform.setTranslation(translation);

}
