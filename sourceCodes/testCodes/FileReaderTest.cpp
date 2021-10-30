#include "FileReader.h"





int main(){

	FileReader newFileReader("camera1.txt");




	while (!newFileReader.endOfFile()) {
		cout << newFileReader.readLine() << endl;
	}

	system("pause");
	return 0;
}