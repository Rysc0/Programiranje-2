#include <iostream>
#include <fstream>
using namespace std;

fstream dat;

class autori{
  public:
    static int ukupno;
    int sif;
    char prez_ime[40];
    char datum_rod[15];
    

    void unos(){
      dat.open("autori.dat", ios::out | ios::app | ios::binary);
      do{
        cout << "Unesi sifur:" << endl;
        cin >> sif;
      }while(sif < 100 || sif > 200);

      cout << "Unesi prezime i ime" << endl;
      cin.ignore();
      cin.getline(prez_ime, 40);
      cout << "Unesi datum rodjenja" << endl;
      cin.getline(datum_rod, 15);
      dat.write((char*)this, sizeof(*this));
      dat.close();
      dat.clear();
      //  broji unose
      autori::ukupno++;
		}

    bool zapisNadjen(int sifra){
      bool nadjen = false;
      dat.open("autori.dat", ios::in | ios::binary);
      while(!dat.eof()){
        dat.read((char*)this, sizeof(*this));
        if(this->sif == sifra)
          nadjen = true;
      }
      dat.close();
      dat.clear();
      if(!nadjen)
        return false;
      else return true;
    }

		void ispis(int sifra = 0){
      if(sifra == 0){
        dat.open("autori.dat", ios::in | ios::binary);
        while(1){ 
          dat.read((char*)this, sizeof(*this));
          if(dat.eof()) break;
          cout << "Sifra autora: " << sif << endl;
          cout << "Prezime i ime: " << prez_ime << endl;
          cout << "Datum rodjenja: " << datum_rod << endl;
          cout << "---------------------------------------" << endl;
        }
        dat.close();
        dat.clear();
      }

      else{
        bool nadjen = false;
        dat.open("autori.dat", ios::in | ios::binary);
        
        while(1){ 
          dat.read((char*)this, sizeof(*this));
          if(dat.eof()) break;
          if(sifra == this->sif){
            cout << "Sifra autora: " << sif << endl;
            cout << "Prezime i ime: " << prez_ime << endl;
            cout << "Datum rodjenja: " << datum_rod << endl;
            cout << "---------------------------------------" << endl;
            nadjen = true;
          }
        }
        if(!nadjen)
          cout << "Nema autora!" << endl;
        dat.close();
        dat.clear();
      }
		}
};

autori var;

class clanci{
  private:
		clanci *sljedeci;
  public:
		static int zbroj;
		int sifra_clanka;
		int sif;
		char naslov[40];
		char vrijeme_unosa[20];
		
    clanci(){
			sljedeci = NULL;
		}


		void unosliste(){
			clanci *zadnji, *novi;
			zadnji = this;
      int sifra_autora;
			while(zadnji->sljedeci)
				zadnji=zadnji->sljedeci;
				
			novi = new clanci;
			zadnji->sljedeci = novi;
			cout << "Sifra clanka: " << endl;
			cin >> novi->sifra_clanka;
      //  onemoguci upis za nepostojeceg autora
      do{
        cout << "Sifra: " << endl;
        cin >> sifra_autora;
      }while(!var.zapisNadjen(sifra_autora));
      // onemoguceno
      novi->sif = sifra_autora;
			cout << "Naslov: " << endl;
			cin.ignore();
			cin.getline(novi->naslov, 40);
			cout << "Vrijeme unosa: " << endl;
			cin.getline(novi->vrijeme_unosa, 20);
      // zbraja sifre clanaka
      clanci::zbroj = clanci::zbroj + novi->sifra_clanka;
		}


		void ispisliste(int sifra, int opcija = 0){
			clanci *tekuci = this->sljedeci;
			bool nadjen = false;

      while(tekuci){
				if(tekuci->sif == sifra){  
					cout << "Sifra clanka: " << tekuci->sifra_clanka << endl;
					cout << "Sifra autora: " << tekuci->sif << endl;
					cout << "Naslov: " << tekuci->naslov << endl;
					cout << "Vrijeme unosa: " << tekuci->vrijeme_unosa << endl;
          cout << "---------------------------------------" << endl;
          nadjen = true;
				}
				tekuci = tekuci->sljedeci;
			}
      if(opcija == 1){
        if(!tekuci && !nadjen)
          cout << "Nema clanka!" << endl;
      }
		}	

    //  provjerava postoji li clanak za danu sifru autora
    bool nadji(int sifra){
      clanci *tekuci = this->sljedeci;
      bool nadjen = false;

      while(tekuci){
        if(tekuci->sif == sifra){
          nadjen = true;
          break;
        } 
        else tekuci = tekuci->sljedeci;
      }
     
      if(nadjen == true) return true;
      else return false;
    }	
};

 
clanci lis;

int autori::ukupno=0;
int clanci::zbroj=0;


int kljuc(){
  int sifra;
  cout << "Unesi sifru: ";
  cin >> sifra;
  return sifra;
}


//  može u funkciji a može i samo cout u case 5
void ispisBrojeva(){
	cout << autori::ukupno << endl;
	cout << clanci::zbroj << endl;
}

void opcija6(int sifra){
  var.ispis(sifra);
  lis.ispisliste(sifra,1);
}


void opcija8(){
  dat.open("autori.dat", ios::in | ios::binary);
  while(!dat.eof()){
    dat.read((char *)&var, sizeof(var));
    if(lis.nadji(var.sif)){
      cout << "Sifra autora: " << var.sif << endl;
      cout << "Prezime i ime: " << var.prez_ime << endl;
      cout << "Datum rodjenja: " << var.datum_rod << endl;
      cout << "---------------------------------------" << endl;
    }
  }
  
  dat.close();
  dat.clear();
}

int main(){

  int jos;
  do{
    cout << "---------------------------------------" << endl;
		cout << "1. Upis u strukturu autori" << endl;
		cout << "2. Ispis svih elemenata strukture autori" << endl;
		cout << "3. Upis u strukturu clanci" << endl;
		cout << "4. Ispis zadanog elementa strukture clanic(korisnik unosi vrijednost atributa sifra)" << endl;
		cout << "5. Ispisite ukupan broj elemenata iz strukture autori i zbroj vrijednosti atrubiuta sifra iz strukture clanci" << endl;
    cout << "6. Ispisi autore za sifru i sve clanke za sifru" << endl;
    cout << "7. Onemoguci unos clanka za nepostojeceg autora" << endl;
    cout << "8. Ispisi sve autore koji imaju barem 1 clanak" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout << "---------------------------------------" << endl;
		cin >> jos;

		switch(jos){
			case 1:
        var.unos();
        break;
			case 2:
        var.ispis();
        break;
			case 3:
        lis.unosliste();
        break;
			case 4:
        lis.ispisliste(kljuc());
        break;
			case 5:
        ispisBrojeva();
        //  može i samo cout autori::ukupno i cout clanci::zbroj
			  break;
      case 6:
        opcija6(kljuc());
        break;
      case 7:
        cout << "implementirano već pod 3" << endl;
        break;
      case 8:
        opcija8();
        break;
	  }
	}while(jos != 9);

	return 0;
}