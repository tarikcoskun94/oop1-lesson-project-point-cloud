#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "FileReader.h"
#include "PointCloud.h"
#include "Transform.h"
#include "PointCloudGenerator.h"
#include "exceptions.h"

/**
 * @file DepthCamera.h
 * @author Tarik COSKUN
 * @date January 3, 2020
 * @brief Bu DepthCamera.h dosyasi DepthCamera classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Derinlik kamersinin karakteristigi burada tanimlanir.
 */

using namespace std;


/**
* \brief <h2><b><i>DepthCamera Nesnesi</i></b></h2>
*
* <p>&emsp;&emsp;Derinlik kamersinin karakteristigi burada tanimlanir.</p>
*/
class DepthCamera : public PointCloudGenerator {
private:
	/**
	* \brief fileName attribute
	*/
	string fileName;

public:
	DepthCamera() {}
	DepthCamera(const string&);

	string getFileName() const;
	void setFileName(string&);

	PointCloud capture() ;
	PointCloud captureFor() ;

	~DepthCamera(){}

};