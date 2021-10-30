#include "RadiusOutlierFilter.h"
/**
* \brief <h2><b><i>RadiusOutlierFilter Constructur.</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametrelere gore yapilan constructor.</p>
*
* \param radius: double radius degeri.
*
*/
RadiusOutlierFilter::RadiusOutlierFilter(double radius) {
	this->radius = radius;
}


/**
* \brief <h2><b><i>setRadius fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;radius degerini set eder.</p>
*
* \param radius: double radius degeri
*
*/

void RadiusOutlierFilter::setRadius(double radius) {
	this->radius = radius;
}
/**
* \brief <h2><b><i>getRadius fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;radius degiskenini dondurur</p>
*
* \return radius
*/
double RadiusOutlierFilter::getRadius() const {
	return radius;
}



/**
* \brief <h2><b><i>filter fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Bir nokta bulutundan gelen degeri gecerli olan radius degerini kontrol ederek tek tek inceler. o noktaya radius degerinden daha yakin baska bir nokta yok ise nokta bulutuna dahil etmez.</p>
*
* \param pc: nokta bulutu
*/

void RadiusOutlierFilter::filter(PointCloud& pc) {

	list <Point> clearRadiusPointLIST;
	//cout << pc.getPointNumber() << endl;
	//system("pause");
	
	list <Point>::iterator it, it2;

	list <Point> pcPointLIST = pc.getPoints();

	for (it = pcPointLIST.begin(); it != pcPointLIST.end(); it++) {
		for (it2 = pcPointLIST.begin(); it2 != pcPointLIST.end(); it2++) {
			if ((it->distance(*it2)) <= radius) {
				if (it == it2) { continue; }
				//cout << endl << "<if> " << i << " - " << j << "  ***  " << pc.getPoints()[i].distance(pc.getPoints()[j]) << " </if>" << endl;
				clearRadiusPointLIST.push_back(*it);
				break;
			}
		}
	}
	//cout << "filter for bitti." << endl;
	//system("pause");
	
	PointCloud pcTMP;
	

	pcTMP.setPoints(clearRadiusPointLIST);

	pc = pcTMP;
}