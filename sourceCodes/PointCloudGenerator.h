#pragma once
#include "Transform.h"
#include "FilterPipe.h"

/**
 * @file PointCloudGenerator.h
 * @author Tarik COSKUN
 * @date January 2, 2020
 * @brief Bu PointCloudGenerator.h dosyasi PointCloudGenerator classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ setFilter ile uygulanacak filterlar ve donusturulecek aci ve uzaklik bilgieri verilir.
 */

 /**
 * \brief <h2><b><i>PointCloudGenerator Nesnesi</i></b></h2>
 *
 * <p>&emsp;&emsp;Abstract class olup , setFilter ile uygulanacak filterlar ve donusturulecek aci ve uzaklik bilgieri verilir.</p>
 */
class PointCloudGenerator {
protected:
	/**
	* \brief transform attribute
	*/
	Transform transform;
	/**
	* \brief filterPipe attribute
	*/
	FilterPipe filterPipe;

public:
	PointCloudGenerator(){}

	virtual PointCloud capture()  = 0;
	virtual PointCloud captureFor()  = 0;
	void setFilterPipe(FilterPipe);
	void setTransform(Transform, Eigen::Vector3d, Eigen::Vector3d);
	
};