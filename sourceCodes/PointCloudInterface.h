#pragma once
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"

/**
 * @file PointCloudInterface.h
 * @author Evren Rahimoglu , Tarik Coskun
 * @date January 2, 2020
 * @brief Bu PointCloudInterface.h dosyasi PointCloudInterface classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Bu sınıf işlemleri basitleştirmek için kullanılan bir sınıftır. captureFor cagirilir ve pointCloud uyesine eklenir.
 */

 /**
 * \brief <h2><b><i>PointCloudInterface Nesnesi</i></b></h2>
 *
 * <p>&emsp;&emsp;Bu sınıf işlemleri basitleştirmek için kullanılan bir sınıftır. captureFor cagirilir ve pointCloud uyesine eklenir.</p>
 */
class PointCloudInterface {

private:
	/**
	* \brief pointCloud attribute
	*/
	PointCloud pointCloud;
	/**
	* \brief patch attribute
	*/
	PointCloud patch;
	/**
	* \brief generators attribute
	*/
	vector<PointCloudGenerator*> generators;
	/**
	* \brief recorder attribute
	*/
	PointCloudRecorder* recorder;

public:

	PointCloudInterface(){}

	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();

	~PointCloudInterface() {}

};
