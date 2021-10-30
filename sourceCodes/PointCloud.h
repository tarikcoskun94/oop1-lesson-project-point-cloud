#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

#include "Point.h"
#include "exceptions.h"

/**
 * @file PointCloud.h
 * @author Tarik COSKUN
 * @date January 2, 2020
 * @brief Bu PointCloud.h dosyasi PointCloud classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Kameradan gelen nokta bulutunun karakteristigi burada tanimlanir.
 */

using namespace std;




/**
* \brief <h2><b><i>PointCloud(NoktaBulutu) Nesnesi</i></b></h2>
*
* <p>&emsp;&emsp;Kameradan gelen nokta bulutunun karakteristigi burada tanimlanir.</p>
*/
class PointCloud {
private:
	/**
	* \brief points attribute
	*/
	list <Point> points;

public:
	PointCloud();

	void setPoints(const list <Point>);

	list <Point> getPoints() const;

	PointCloud operator +(PointCloud&);
	void operator =(const PointCloud&);

	~PointCloud(){}
};