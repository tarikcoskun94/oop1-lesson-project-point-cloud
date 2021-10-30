#pragma once
#include"PointCloud.h"
#include"PointCloudFilter.h"

/**
 * @file PassThroughFilter.h
 * @author Can Cetiner , Nail Emre Kayapinar
 * @date January 3, 2020
 * @brief Bu PassThroughFilter.h dosyasi PassThroughFilter classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Her bir kordinat sistemini kendi upper ve lower limitlerine gore ayristirir ve filtrelenmesi icin gerekli islemleri yapar
 */

/**
* \brief <h2><b><i>PassThroughFilter class</i></b></h2>
*
* <p>&emsp;&emsp;Her bir kordinat sistemini kendi upper ve lower limitlerine gore ayristirir ve filtrelenmesi icin gerekli islemleri yapar</p>
*/

class PassThroughFilter : public PointCloudFilter {
private:
	/**
	* \brief upperLimitX attribute
	*/
	double upperLimitX;
	/**
	* \brief lowerLimitX attribute
	*/
	double lowerLimitX;
	/**
	* \brief upperLimitY attribute
	*/
	double upperLimitY;
	/**
	* \brief lowerLimitY attribute
	*/
	double lowerLimitY;
	/**
	* \brief upperLimitZ attribute
	*/
	double upperLimitZ;
	/**
	* \brief lowerLimitZ attribute
	*/
	double lowerLimitZ;

public:
	PassThroughFilter(){}
	PassThroughFilter(double, double, double, double, double, double);

	void setUpperLimitX(double);
	double getUpperLimitX() const;

	void setLowerLimitX(double);
	double getLowerLimitX() const;

	void setUpperLimitY(double);
	double getUpperLimitY() const;

	void setLowerLimitY(double);
	double getLowerLimitY() const;

	void setUpperLimitZ(double);
	double getUpperLimitZ() const;

	void setLowerLimitZ(double);
	double getLowerLimitZ() const;

	void filter(PointCloud& pc);

	
	~PassThroughFilter() {}





};
