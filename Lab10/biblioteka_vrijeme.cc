//Mjerenje proteklog vremena u tisuèinkama sekundi
#include<time.h>
#include<iostream>
using namespace std;
clock_t vrijeme1,vrijeme2;
double razlika;
double vrijeme_pocetak(){
  vrijeme1=clock();
	return (double)vrijeme1;
};
double vrijeme_kraj(){
	vrijeme2=clock();
	return (double)vrijeme2;
};
double vrijeme_proteklo(){
	razlika=vrijeme2-vrijeme1;
	return razlika;
};
//unos znakovnog niza
void unos(char *znakovni_niz)
{
	cin.getline(znakovni_niz, 150);
	if (cin.gcount()==1)
	  	 cin.getline (znakovni_niz,150);
};
