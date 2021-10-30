#pragma once
#include <iostream>
#include <string>

/**
 * @file exception.h
 * @author Tarik COSKUN
 * @date January 2, 2020
 * @brief Bu exception.h dosyasi exception classini tanimlar
 * @ attributes ve uye fonksiyonlarini olusturur.
 * @ Try-Catch icin yazilmis class.
 */

using namespace std;

class errorWriteFile : public exception {
public:
	string message(string);
};

class errorWriteLine : public exception {
public:
	string message();
};

class errorReadFile : public exception {
public:
	string message(string);
};

class errorLineFormat : public exception {
public:
	string message();
};

class errorZeroPoint : public exception {
public:
	string message();
};