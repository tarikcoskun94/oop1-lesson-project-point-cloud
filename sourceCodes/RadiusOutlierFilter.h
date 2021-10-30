#pragma once
#include <iostream>
#include <vector>

#include "PointCloud.h"
#include "PointCloudFilter.h"

/**
 * @file RadiusOutlierFilter.h
 * @author Evren Rahimoglu
 * @date December 15, 2019
 * @brief Bu RadiusOutlierFilter.h dosyasi RadiusOutlierFilter classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ bir radius degeri alir ve butun noktalari birbirine gore tek tek kontrol eder
 * @ eger bir noktaya radiustan daha yakin bir deger yoksa o nokta , nokta bulutuna dahil edilmez
 * @ boylece filtreleme islemi tamamlanmis olur.
 * @
 */

/**
* \brief <h2><b><i>RadiusOutlierFilter class</i></b></h2>
*
* <p>&emsp;&emsp;butun noktalari tek tek kontrol eder ve o noktaya radius degerinden daha yakin baska bir nokta yoksa o noktayi nokta bulutuna dahil etmez ve filtreler.</p>
*/
class RadiusOutlierFilter : public PointCloudFilter {
private:
	/**
	* \brief radius attribute
	*/
	double radius;

public:
	RadiusOutlierFilter(){}
	RadiusOutlierFilter(double);

	void setRadius(double);
	double getRadius() const;

	void filter(PointCloud&);

	~RadiusOutlierFilter(){}
};