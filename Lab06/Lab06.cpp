#include <iostream>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"
#include <fstream>
#include <iomanip>
using namespace std;

struct data_t{
	int sifra;
	char prez_ime[50];
	char naslov[50];
	double vrijeme_unosa;
};

data_t podatak;
tindeks ind;
fstream file;
fstream indeks;

void input(){
	file.open("datoteka.dat", ios::in | ios::binary);
	indeks.open("datoteka.ind", ios::in | ios::binary);
	if(!file && !indeks) {
		file.open("datoteka.dat", ios::out | ios::binary);
		indeks.open("datoteka.ind", ios::out | ios::binary);
	}
	else {
		file.close();
		indeks.close();
		file.open("datoteka.dat", ios::out | ios::in | ios::ate | ios::binary);
		indeks.open("datoteka.ind", ios::out | ios::in | ios::ate | ios::binary);
	}
	while(1){
		vrijeme_pocetak();
		cout<<"sifra: ";
		cin>>podatak.sifra;
		cout<<"prezime i ime: ";
		unos(podatak.prez_ime);
		cout<<"naslov: ";
		unos(podatak.naslov);
		vrijeme_kraj();
		podatak.vrijeme_unosa=(vrijeme_proteklo()/(1000));
		cout<<"vrijeme unosa je: "<<fixed << setprecision(1)<<podatak.vrijeme_unosa<<endl;
		if(podatak.vrijeme_unosa<5) {
			cout<<"prekratko"<<endl;
			break;
		}
	}
	
	
	if(podatak.vrijeme_unosa>5){
		file.write((char*)&podatak, sizeof(podatak));
		ind.kljuc = podatak.sifra;
		ind.adresa = (int)file.tellp()-sizeof(podatak);
		indeks.write((char*)&ind, sizeof(tindeks));		
	}
	
	file.close();
	indeks.close();
}


int main(){



int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. rucni unos podataka u datoteku" << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            // function
            input();
            break;
        case 2:
            // function
            break;
        case 3:
            // function
            break;
        case 4:
            // function
            break;
    }
}while(jos != 9);
 
 
    return 0;
}