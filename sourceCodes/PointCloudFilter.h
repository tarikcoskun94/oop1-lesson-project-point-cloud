#pragma once
#include "PointCloud.h"

/**
 * @file PointCloudFilter.h
 * @author Can Cetiner , Nail Emre Kayapinar
 * @date January 3, 2020
 * @brief Bu PointCloudFilter.h dosyasi PointCloudFilter classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Gelen verilerin gecmesi gereken filterlar burda tutulur
 */


 /**
 * \brief <h2><b><i>PointCloudFilter Nesnesi</i></b></h2>
 *
 * <p>&emsp;&emsp;Gelen verilerin gecmesi gereken filterlar burda tutulur</p>
 */
class PointCloudFilter {

public:

	PointCloudFilter(){}
	virtual void filter(PointCloud& pc) = 0;
	~PointCloudFilter(){}
};
