#pragma once
#include "PointCloudFilter.h"

/**
 * @file FilterPipe.h
 * @author Can Cetiner , Nail Emre Kayapinar
 * @date January 3, 2020
 * @brief Bu FilterPipe.h dosyasi FilterPipe classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Uygulanacak filterler filters vectorune addFilter ile eklenir ve uygulanacagi zaman filterOut ile uygulanir.
 */

/**
* \brief <h2><b><i>FilterPipe classi</i></b></h2>
*
* <p>&emsp;&emsp;Uygulanacak filterler filters vectorune addFilter ile eklenir ve uygulanacagi zaman filterOut ile uygulanir.</p>
*/
class FilterPipe {

private:

	vector<PointCloudFilter*> filters;

public:

	FilterPipe(){}
	void addFilter(PointCloudFilter* filter);
	void filterOut(PointCloud& pc);
	~FilterPipe(){}

};