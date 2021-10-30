#include "Point.h"


/**
* \brief <h2><b><i>Default Constructor</i></b></h2>
*
* <p>&emsp;&emsp;Nesne yaratilirken tum degerlerini sifira esitler.</p>
*
*/
Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}



/**
* \brief <h2><b><i>x icin setter</i></b></h2>
*
* <p>&emsp;&emsp;x degerinin set eder.</p>
*
* \param x: x degeri
*/
void Point::setX(double x) {
	this->x = x;
}

/**
* \brief <h2><b><i>x icin getter</i></b></h2>
*
* <p>&emsp;&emsp;x degerini dondurur.</p>
*
* \return x
*/
double Point::getX() const {
	return x;
}



/**
* \brief <h2><b><i>y icin setter</i></b></h2>
*
* <p>&emsp;&emsp;y degerinin set eder.</p>
*
* \param y: y degeri
*/
void Point::setY(double y) {
	this->y = y;
}

/**
* \brief <h2><b><i>y icin getter</i></b></h2>
*
* <p>&emsp;&emsp;y degerini dondurur.</p>
*
* \return y
*/
double Point::getY() const {
	return y;
}



/**
* \brief <h2><b><i>z icin setter</i></b></h2>
*
* <p>&emsp;&emsp;z degerinin set eder.</p>
*
* \param z: z degeri
*/
void Point::setZ(double z) {
	this->z = z;
}

/**
* \brief <h2><b><i>z icin getter</i></b></h2>
*
* <p>&emsp;&emsp;z degerini dondurur.</p>
*
* \return z
*/
double Point::getZ() const {
	return z;
}



/**
* \brief <h2><b><i>2 nokta arasi uzaklik</i></b></h2>
*
* <p>&emsp;&emsp;Nokta, kendisi ile kendisine verilen baska bir nokta arasindaki uzakligi hesaplayip geriye dondurur.</p>
*
* \param ctrlDisPoint: ikinci nokta
* \return distance
*/
double Point::distance(const Point& ctrlDisPoint) const {
	double difX = this->x - ctrlDisPoint.x;
	double difY = this->y - ctrlDisPoint.y;
	double difZ = this->z - ctrlDisPoint.z;

	double sumOfSquares = pow(difX, 2) + pow(difY, 2) + pow(difZ, 2);

	double distance = sqrt(sumOfSquares);

	return distance;
}



/**
* \brief <h2><b><i>2 nokta kiyaslama</i></b></h2>
*
* <p>&emsp;&emsp;Nokta, kendisi ile kendisine verilen baska bir noktanin esitligini kiyaslayip geriye true/false dondurur.</p>
*
* \param cmpPoint: ikinci nokta
* \return true/false
*/
bool Point::operator == (const Point& cmpPoint) const {
	if (this->x == cmpPoint.x && this->y == cmpPoint.y && this->z == cmpPoint.z) {
		return true;
	}
	else {
		return false;
	}
}