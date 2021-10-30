#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "exceptions.h"

/**
 * @file FileReader.h
 * @author Tarik COSKUN
 * @date January 2, 2020
 * @brief Bu FileReader.h dosyasi FileReader classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Dosyanin nasil okunacagi burada tanimlanir.
 */

using namespace std;


/**
* \brief <h2><b><i>FileReader Nesnesi</i></b></h2>
*
* <p>&emsp;&emsp;Dosyanin nasil okunacagi burada tanimlanir.</p>
*/
class FileReader {
private:
	/**
	* \brief filePath attribute
	*/
	string filePath;
	/**
	* \brief theFile attribute
	*/
	ifstream theFile;

public:
	FileReader(){}
	FileReader(const string&);

	void setFilePath(const string&);
	string getFilePath() const;

	bool endOfFile();

	//vector <string> readLine();
	string readLine();

	~FileReader(){}

};