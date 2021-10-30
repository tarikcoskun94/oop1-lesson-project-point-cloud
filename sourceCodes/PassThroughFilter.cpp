#include "PassThroughFilter.h"

/**
* \brief <h2><b><i>Constructur.</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametrelere gore yapilan constructor.</p>
*
* \param upperLimitX: X in max siniri
* \param lowerLimitX: X in min siniri
* \param upperLimitY: Y in max siniri
* \param lowerLimitY: Y in min siniri
* \param upperLimitZ: Z in max siniri
* \param lowerLimitZ: Z in min siniri
*
*/
PassThroughFilter::PassThroughFilter(double upperLimitX , double lowerLimitX , double upperLimitY, double lowerLimitY, double upperLimitZ, double lowerLimitZ) {

	this->upperLimitX = upperLimitX;
	this->lowerLimitX = lowerLimitX;
	this->upperLimitY = upperLimitY;
	this->lowerLimitY = lowerLimitY;
	this->upperLimitZ = upperLimitZ;
	this->lowerLimitZ = lowerLimitZ;


}




/**
* \brief <h2><b><i>setUpperLimitX fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;upperLimitX degerini set eder.</p>
*
* \param upperLimitX:
*
*/
void PassThroughFilter::setUpperLimitX(double upperLimitX) {

	this->upperLimitX = upperLimitX;

}
/**
* \brief <h2><b><i>getUpperLimitX fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;upperLimitX degiskenini dondurur</p>
*
* \return upperLimitX
*/
double PassThroughFilter::getUpperLimitX() const {

	return upperLimitX;

}




/**
* \brief <h2><b><i>setLowerLimitX fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;lowerLimitX degerini set eder.</p>
*
* \param lowerLimitX:
*
*/
void PassThroughFilter::setLowerLimitX(double lowerLimitX) {

	this->lowerLimitX = lowerLimitX;

}
/**
* \brief <h2><b><i>getLowerLimitX fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;lowerLimitX degiskenini dondurur</p>
*
* \return lowerLimitX
*/
double PassThroughFilter::getLowerLimitX() const {

	return lowerLimitX;

}





/**
* \brief <h2><b><i>setUpperLimitY fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;upperLimitY degerini set eder.</p>
*
* \param upperLimitY:
*
*/
void PassThroughFilter::setUpperLimitY(double upperLimitY) {

	this->upperLimitY = upperLimitY;

}
/**
* \brief <h2><b><i>getUpperLimitY fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;upperLimitY degiskenini dondurur</p>
*
* \return upperLimitY
*/
double PassThroughFilter::getUpperLimitY() const {

	return upperLimitY;

}





/**
* \brief <h2><b><i>setLowerLimitY fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;lowerLimitY degerini set eder.</p>
*
* \param lowerLimitY:
*
*/
void PassThroughFilter::setLowerLimitY(double lowerLimitY) {

	this->lowerLimitY = lowerLimitY;


}
/**
* \brief <h2><b><i>getLowerLimitY fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;lowerLimitY degiskenini dondurur</p>
*
* \return lowerLimitY
*/
double PassThroughFilter::getLowerLimitY() const {

	return lowerLimitY;

}



/**
* \brief <h2><b><i>setUpperLimitZ fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;upperLimitZ degerini set eder.</p>
*
* \param upperLimitZ:
*
*/

void PassThroughFilter::setUpperLimitZ(double upperLimitZ) {

	this->upperLimitZ = upperLimitZ;

}
/**
* \brief <h2><b><i>getUpperLimitZ fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;upperLimitZ degiskenini dondurur</p>
*
* \return upperLimitZ
*/
double PassThroughFilter::getUpperLimitZ() const {

	return upperLimitZ;

}



/**
* \brief <h2><b><i>setLowerLimitZ fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;lowerLimitZ degerini set eder.</p>
*
* \param lowerLimitZ:
*
*/

void PassThroughFilter::setLowerLimitZ(double lowerLimitZ) {

	this->lowerLimitZ = lowerLimitZ;

}
/**
* \brief <h2><b><i>getLowerLimitZ fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;lowerLimitZ degiskenini dondurur</p>
*
* \return lowerLimitZ
*/
double PassThroughFilter::getLowerLimitZ() const {

	return lowerLimitZ;

}



/**
* \brief <h2><b><i>filter fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;nokta bulutundan gelen noktalari tek tek kontrol eder ve upperLimit ustunde kalirsa veya lowerlimitin altinda kalirsa bu noktayi dahil etmez.</p>
*
* \param pc: nokta bulutu alir
*/

void PassThroughFilter::filter(PointCloud& pc) {

	list <Point> clearRadiusPointLIST;

	list <Point>::iterator it;

	list <Point> pcPointLIST = pc.getPoints();

	for (it = pcPointLIST.begin(); it != pcPointLIST.end(); it++)
	{
		if ((it->getX() <= upperLimitX && it->getX() >= lowerLimitX)
			&& (it->getY() <= upperLimitY && it->getY() >= lowerLimitY)
			&& (it->getZ() <= upperLimitZ && it->getZ() >= lowerLimitZ))
		{
			clearRadiusPointLIST.push_back(*it);


		}
	}
	

	PointCloud pcTMP;


	pcTMP.setPoints(clearRadiusPointLIST);

	pc = pcTMP;
}