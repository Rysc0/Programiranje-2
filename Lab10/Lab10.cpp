#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <cstring>
using namespace std;


// kljuc za povezivanje listi je šifra_predmeta
class predmeti_zapis{
  public:
    int sifra_predmeta;
    char naziv_predmeta[20];
    char smjer[20];
    //  za pobrojat kolko unosa ima
    static int brojac;

    void input(){
      cout << "Unesi sifru predmeta: ";
      cin >> sifra_predmeta;
      cout << "Unesi naziv predmeta: ";
      unos(naziv_predmeta);
      cout << "Unesi smjer: ";
      unos(smjer);
      brojac++;
    }
    void ispis(){
      cout << sifra_predmeta << "\t" << naziv_predmeta << "\t" << smjer << endl;
    }

};

// lista 1
class predmeti{
  public:
    predmeti_zapis zapis;
    predmeti *next;
    // metode prema potrebi

    void input(){
      zapis.input();
    }

    void displayOutput(){
      cout << zapis.sifra_predmeta << "\t" << zapis.naziv_predmeta << "\t"<< zapis.smjer << endl;
    }
  
   
};
 
class prijave_zapis{
  public:
    int sifra_prijave;
    int sifra_predmeta;
    int maticni_br;
    char rok[10];

    void unos(int sifraPredmeta){
      sifra_predmeta = sifraPredmeta;
      cout << "Unesi sifru prijave: ";
      cin >> sifra_prijave;
      cout << "Unesi maticni broj: ";
      cin >> maticni_br;
      cout << "Unesi rok: ";
      cin >> rok;
    }

    void ispis(){
      cout << sifra_prijave << "\t" << maticni_br << "\t" << rok << endl;
    }
};

// lista 2
class prijave{
  public:
    prijave_zapis *prijavnica;
    prijave *next;
    // metode prema potrebi

    // Koristiti konstruktor za dinamičku alokaciju vezanog objekta kod sadržavanja 
    // po referenci (metoda ispisuje tekst "Konstruktor"). 
    public:
    prijave(){
      cout << "Konstruktor" << endl;
      prijavnica = new prijave_zapis;
    }
    ~prijave(){
      cout << "Destruktor" << endl;
      delete prijavnica;
    }

  void input(int sifraPredmeta){
    prijavnica->unos(sifraPredmeta);
  }

  void output(){
    prijavnica->ispis();
  }

};

predmeti *predmet_lista;
prijave *prijava_lista;
int predmeti_zapis::brojac;


void novi_predmet(){
  predmeti *zadnji, *tekuci, *novi;
  cout << "Uneseno je : " << predmeti_zapis::brojac << " zapisa" << endl;
  if(predmet_lista == NULL){
    predmet_lista = new predmeti;
    predmet_lista->next = NULL;
  }

  zadnji = predmet_lista;
  while(zadnji->next)
    zadnji = zadnji->next;
  
  novi = new predmeti;
  zadnji->next = novi;
  novi->next = NULL;
  novi->input();

  cout << "Sifra\t" << "Naziv\t" << "Smjer" << endl;
  cout << "---------------------------------" << endl;
  tekuci = predmet_lista->next;
  while(tekuci){
    tekuci->displayOutput();
    tekuci = tekuci->next;
  }

}

void popis_predmeta(){
  predmeti *tekuci;
  char naziv_smjera[20];
  cout << "Unesi naziv smjera: ";
  unos(naziv_smjera);

  tekuci = predmet_lista->next;
  while(tekuci){
    if(strcmp(tekuci->zapis.smjer,naziv_smjera) == 0)
      tekuci->displayOutput();
    tekuci = tekuci->next;
  }

}

void unos_prijave(){
  predmeti *tekuci;
  prijave *zadnji, *novi; // tekuci vjv ne treba
  int sifraPredmeta;
  bool found = false;

  if(prijava_lista == NULL){
    prijava_lista = new prijave;
    prijava_lista->next = NULL;
  }
   
  cout << "Unesi sifru predmeta: ";
  cin >> sifraPredmeta;
  tekuci = predmet_lista->next;
  while(tekuci){
    if(tekuci->zapis.sifra_predmeta == sifraPredmeta)
      found = true;
    
    tekuci = tekuci->next;
  }

  if(found){
    cout << "Predmet pronadjen!" << endl;
    zadnji = prijava_lista;
    while(zadnji->next)
      zadnji = zadnji->next;

    novi = new prijave;
    zadnji->next = novi;
    novi->next = NULL;
    novi->input(sifraPredmeta); //prosljeduje se sifra predmeta
  }
  
  else cout << "Predmet ne postoji!" << endl;

}


void ispis_prijave(){
  predmeti *tekuci;
  prijave *tekuci_2;
  int sifraPredmeta;

  cout << "Unesi sifru predmeta: ";
  cin >> sifraPredmeta;
  tekuci = predmet_lista->next;

  while(tekuci){
    if(tekuci->zapis.sifra_predmeta == sifraPredmeta){
      cout << "Naziv predmeta: " << tekuci->zapis.naziv_predmeta << endl;
      cout << "Naziv smjera: " << tekuci->zapis.smjer << endl;
    }
    tekuci = tekuci->next;
  }

  tekuci_2 = prijava_lista->next;
  cout << "Sifra\t" << "Maticni\t" << "Rok" << endl;
  cout << "-------------------------------------" << endl;
  while(tekuci_2){
    if(tekuci_2->prijavnica->sifra_predmeta == sifraPredmeta){
      tekuci_2->output();
      cout << "Sljedeci: " << tekuci_2->next << endl;
      cout << "............................" << endl;
    }
    tekuci_2 = tekuci_2->next;
  }



}

int main(){

// glave listi 
predmet_lista = NULL;
prijava_lista = NULL;
predmeti_zapis::brojac = 0;


int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Upis predmeta na kraj liste predmeta i ispis cijele liste predmeta" << endl;
    cout << "2. Popis predmeta zadanog smjera" << endl;
    cout << "3. Unos prijave na kraj liste prijava" << endl;
    cout << "4. Ispis liste prijava za zadani predmet" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            // function
            novi_predmet();
            break;
        case 2:
            // function
            popis_predmeta();
            break;
        case 3:
            // function
            unos_prijave();
            break;
        case 4:
            // function
            ispis_prijave();
            break;
    }
}while(jos != 9);
 
 
    return 0;
}