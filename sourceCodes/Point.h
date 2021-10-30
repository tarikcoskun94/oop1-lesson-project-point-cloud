#pragma once
#include <iostream>
#include <cmath>

/**
 * @file Point.h
 * @author Tarik COSKUN
 * @date January 2, 2020
 * @brief Bu Point.h dosyasi Point classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Kameradan gelen nokta bulutunu olusturan her bir noktanin karakteristigi burada tanimlanir.
 */

using namespace std;


/**
* \brief <h2><b><i>Point(Nokta) Nesnesi</i></b></h2>
*
* <p>&emsp;&emsp;Kameradan gelen nokta bulutunu olusturan her bir noktanin karakteristigi burada tanimlanir.</p>
*/
class Point {
private:
	/**
	* \brief x attribute
	*/
	double x;
	/**
	* \brief x attribute
	*/
	double y;
	/**
	* \brief x attribute
	*/
	double z;

public:
	Point();

	void setX(double);
	double getX() const;

	void setY(double);
	double getY() const;

	void setZ(double);
	double getZ() const;

	double distance(const Point&) const;

	bool operator == (const Point&) const;

	~Point(){}
};