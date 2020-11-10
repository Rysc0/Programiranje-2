//Čitanje tekstualne datoteke
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main(){
	char red[80];
    char redak;
	fstream dat;
	dat.open("Siemens_poslovni_slucaj.txt",ios::in);
	while(1){
        // dat.read(red,sizeof(red));
        dat.read((char *) &redak, sizeof(redak));
	//    dat.getline (red,sizeof(red),'\0');	// čitanje reda iz datoteke
	   if (dat.eof()) break;
	   cout << red << endl;
	};
	dat.close();dat.clear();
  return 1;
}