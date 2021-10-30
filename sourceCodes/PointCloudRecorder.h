#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"PointCloud.h"
#include "exceptions.h"

using namespace std;

/**
 * @file PointCloudRecorder.h
 * @author Evren Rahimoglu
 * @date December 13, 2019
 * @brief Bu PointCloudRecorder.h dosyasi PointCloudRecorder classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @son hale getirilmis bir PointCloud turunden tuttugumuz butun kordinat verilerini
 * @dosyaya yazdirir.
 */


/**
* \brief <h2><b><i>PointCloudRecorder class</i></b></h2>
*
* <p>&emsp;&emsp;Nokta bulutunun butun islemlerden gectikten sonra dosyaya aktarmak icin oluturulmus class.</p>
*/

class PointCloudRecorder {

private:
	/**
	* \brief fileName attribute
	*/
	string fileName;
	/**
	* \brief myfile attribute
	*/
	ofstream myfile;

public:
	
	PointCloudRecorder(){}					 
	PointCloudRecorder(string&);
	void setfileName(string&);				
	string getfileName();					
	bool save(const PointCloud& pc);
	void close();
	~PointCloudRecorder(){}					

};
