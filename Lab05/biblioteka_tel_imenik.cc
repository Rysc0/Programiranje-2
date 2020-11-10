//vremenske funkcije
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
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
//funkcije za unos podataka
void unos(char *znakovni_niz)
{
	cin.getline(znakovni_niz, 150);
	if (cin.gcount()==1)
	  	 cin.getline (znakovni_niz,150);
};
int unos_tel(int &tel){//upakira tel. broj u podatak tipa int
	int i,pomak=0;
	char tel_niz[20];
  char *pokaz_kraja=(char *)""; // \0
	cout << "00";
	cin.getline(tel_niz, 150);
	if (cin.gcount()==1)
	  	 cin.getline (tel_niz,150);
	for (i=0;i<(int)strlen(tel_niz);i++){ // izbacivanje razmaka
    if (tel_niz[i]==' ') pomak++;
    else
      tel_niz[i-pomak]=tel_niz[i];
  };
  tel_niz[i-pomak]='\0';
	tel=strtol(tel_niz,&pokaz_kraja,10);// vra�a nulu ako nije broj
	if (tel<1000000) tel=0; // manje od 7 znamenki
	return tel;
};
void stanje_dat_objekta(fstream& dat){  //argument tipa fstream mora biti referenca!
  cout << "-----<Stanje datotecnog objekta>-----" << endl;
  if (dat.is_open() == false){
    cout << "Datoteka nije otvorena!" << endl;
    return;
    }

  cout << "Datotecni pokazivac za citanje: " << dat.tellg() << endl;
  cout << "Datotecni pokazivac za upis: " << dat.tellp() << endl;
  if (dat.eof()){
    cout << "Kraj datoteke!" << endl;
  }
  if (dat.good()){
    cout << "Datoteka je spremna za upis/citanje." << endl;
  } else {
    cout << "Datoteka trenutno nije spremna za upis/citanje." << endl;
  }
  cout << "Stanje zastavice pogreske: " << dat.rdstate() << endl;

  int pamti=dat.tellg();
  dat.seekg (0, ios::end); // relativna pozicija u odnosu na kraj datoteke
  cout << "Velicina datoteke (b): " << dat.tellg() << endl;
  dat.seekg(pamti);
};//stanje_dat_objekta


