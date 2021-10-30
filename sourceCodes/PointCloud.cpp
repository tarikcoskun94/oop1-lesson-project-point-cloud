#include "PointCloud.h"


/**
* \brief <h2><b><i>Parametre ile default Constructor</i></b></h2>
*
* <p>&emsp;&emsp;Nesne yaratilirken nokta sayisini hafizaya alir ve nokta sayisi kadar bellekten Point tipinde yer ayirir.</p>
*
* \param pointNumber: Nokta adedi
*/
PointCloud::PointCloud() {
	
}



/**
* \brief <h2><b><i>points icin setter</i></b></h2>
*
* <p>&emsp;&emsp;Dinamik olarak points arrayi doldurulur.</p>
*
* \param points: Nokta pointeri
*/
void PointCloud::setPoints(const list <Point> points) {
	try {
		if (points.size() < 1) { throw errorZeroPoint(); }
		this->points.clear();
		this->points = points;
	}
	catch (errorZeroPoint error) {
		error.message();
	}
}



/**
* \brief <h2><b><i>points icin getter</i></b></h2>
*
* <p>&emsp;&emsp;points degerini dondurur.</p>
*
* \return points
*/
list <Point> PointCloud::getPoints() const {
	return this->points;
}



/**
* \brief <h2><b><i>2 nokta bulutunun kesisim kumesi</i></b></h2>
*
* <p>&emsp;&emsp;Nokta bulutu, kendisi ile kendisine verilen baska bir nokta bulutu arasindaki kesimi tespit edip geriye dondurur.</p>
*
* \param joinablePointCloud: ikinci nokta bulutu
* \return intersectionPointCloud
*/
PointCloud PointCloud::operator +(PointCloud& secondPointCloud) {
	// Bu vekt�rler, nokta bulutundaki ayn� noktalar�n ayr��t�r�lmas� s�ras�nda kullan�l�yor.
	list <Point> thisPointLIST;
	list <Point> secondPointLIST;
	list <Point> joinedPointLIST;

	bool same = false; // ayn� noktan�n varl�k durumunu bildirir.

	list <Point>::iterator it, it2;
	for (it = this->points.begin(); it != this->points.end(); it++) { // (This PointCloud icin) Bu iki dongu ile dizideki her nokta, kendisinden sonraki tum noktalar ile esit mi diye kontrol edilir.
		for (it2 = next(it, 1); it2 != this->points.end(); it2++) {
			if ((*it) == (*it2)) {
				same = true;
				break;
			}
			else {
				same = false;
			}
		}

		if (same == true && it != prev(this->points.end(), 1)) { continue; } // Ayn� noktan�n varlik durumu varsa ve sonuncu eleman uzerinde de degil isek dongu basa atilir ve 
		thisPointLIST.push_back(*it);					 // vektore alma satiri calistirilamaz.
	}


	this->points = thisPointLIST;

	same = false;

	for (it = secondPointCloud.points.begin(); it != secondPointCloud.points.end(); it++) { // (Ikinci PointCloud icin) ...
		for (it2 = next(it, 1); it2 != secondPointCloud.points.end(); it2++) {
			if ((*it) == (*it2)) {
				same = true;
				break;
			}
			else {
				same = false;
			}
		}

		if (same == true && it != prev(secondPointCloud.points.end(), 1)) { continue; }
		secondPointLIST.push_back(*it);
	}


	secondPointCloud.points = secondPointLIST;


	for (it = thisPointLIST.begin(); it != thisPointLIST.end(); it++) { // Bu iki dongu, temizlenmi� noktlardan olu�an vekt�rleri tek bir vekt�rde birle�tirir.
		joinedPointLIST.push_back(*it);
	}
	for (it = secondPointLIST.begin(); it != secondPointLIST.end(); it++) { // Bu iki dongu, temizlenmi� noktlardan olu�an vekt�rleri tek bir vekt�rde birle�tirir.
		joinedPointLIST.push_back(*it);
	}



	PointCloud joinedPointCloud; //exit(0);
	
	joinedPointCloud.points = joinedPointLIST;

	return joinedPointCloud; // Birle�tirilmi� nokta bulutu d�nd�r�l�yor
}

/**
* \brief <h2><b><i>Nokta bulutu atama ("=" operatoru)</i></b></h2>
*
* <p>&emsp;&emsp;Bir nokta bulutuna "=" operatoru ile baska bir nokta bulutunu atar.</p>
*
* \param copyablePointCloud: ikinci nokta bulutu
*/
void PointCloud::operator =(const PointCloud& copyablePointCloud) {
	this->points.clear();
	this->points = copyablePointCloud.points;
}