
#pragma once
#include"PointCloud.h"
#include<iostream>
#include<cmath>
#include<iomanip>
#include<Eigen/Dense>


#define PI 3.14159265359
using namespace std;

/**
 * @file Transform.h
 * @author Evren Rahimoglu
 * @date December 11, 2019
 * @brief Bu Transform.h dosyasi Transform classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ iki kordinat orijinin birbirine olan uzakligi (trans) ve aci farki (angles) degerleri
 * @ ilgili dizilere atilir. bu trans ve angles degerlerine gore transMatrix olusturulur.
 * @ transMatrix ve dosyadan gelen bir noktaya gore transform yapilir.
 * @dosyaya yazdirir.
 */


/**
* \brief <h2><b><i>Transform class</i></b></h2>
*
* <p>&emsp;&emsp; iki koordinat ekseni orijinleri arasındaki uzaklık ve rotasyon acilarini alip donusume tabi tutan class</p>
*/

class Transform {

private:
	/**
	* \brief angles attribute
	*/
	Eigen::Vector3d angles;
	/**
	* \brief trans attribute
	*/
	Eigen::Vector3d trans;
	/**
	* \brief transMatrix attribute
	*/
	Eigen::Matrix4d transMatrix;


public:
	Transform();
	void setAnglesX(double);
	double getAnglesX();

	void setAnglesY(double);
	double getAnglesY();
	
	void setAnglesZ(double);
	double getAnglesZ();

	void setTransX(double);
	double getTransX();

	void setTransY(double);
	double getTransY();

	void setTransZ(double);
	double getTransZ();

	Eigen::Matrix4d getTransMatrix();

	void setRotation(double angles[]);
	void setTranslation(double trans[]);
	void setRotation(Eigen::Vector3d ang);
	void setTranslation(Eigen::Vector3d trans);

	Point doTransform(Point p);
	PointCloud doTransform(PointCloud pc);

	
	
};