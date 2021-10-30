#include "exceptions.h"


string errorWriteFile::message(string filePath) {
	cout << "!!! HATA !!! - Dosya yaratilamadi veya yazmak icin acilamadi: " << filePath << endl;
	cout << "Program sonlandirilacak." << endl << endl;
	system("pause");
	exit(0);
}

string errorWriteLine::message() {
	cout << "!!! HATA !!! - Bir satir kaydedilemedi." << endl;
	cout << "Program sonlandirilacak." << endl << endl;
	system("pause");
	exit(0);
}

string errorReadFile::message(string filePath) {
	cout << "!!! HATA !!! - Dosya okumak icin acilamadi: " << filePath << endl;
	cout << "Program sonlandirilacak." << endl << endl;
	system("pause");
	exit(0);
}

string errorLineFormat::message() {
	cout << "!!! HATA !!! - Lutfen dosyadaki satirlarinizi uygun formatta oldugundan emin olun." << endl;
	cout << "Program sonlandirilacak." << endl << endl;
	system("pause");
	exit(0);
}

string errorZeroPoint::message() {
	cout << "!!! HATA !!! - Nokta bulutunu en az 1 adet nokta ile baslatmalisiniz." << endl;
	cout << "Program sonlandirilacak." << endl << endl;
	system("pause");
	exit(0);
}