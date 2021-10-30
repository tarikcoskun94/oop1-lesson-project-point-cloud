#include "FilterPipe.h"

/**
* \brief <h2><b><i>addFilter fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Parametre olarak alinan PointCloudFilter* tipinden gelen filter uyesi filters vectorune eklenir.</p>
*
* \param filter: PointCloudFilter*
*/
void FilterPipe::addFilter(PointCloudFilter* filter) {

	filters.push_back(filter);

}
/**
* \brief <h2><b><i>filterOut fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;Parametre olarak gelen PointCloud u filterlardan gecirme islemini yapar.</p>
*
* \param pc: PointCloud&
*/
void FilterPipe::filterOut(PointCloud& pc) {

	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(pc);
	}


}