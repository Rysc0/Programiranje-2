#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;


// kljuc za povezivanje listi je šifra_predmeta
class predmeti_zapis{
  public:
    int sifra_predmeta;
    char naziv_predmeta[20];
    char smjer[20];

    void input(){
      cout << "Unesi sifru predmeta: ";
      cin >> sifra_predmeta;
      cout << "Unesi naziv predmeta: ";
      unos(naziv_predmeta);
      cout << "Unesi smjer: ";
      unos(smjer);
    }
    void ispis(){
      cout << sifra_predmeta << " " << naziv_predmeta << " " << smjer << endl;
    }

};

class predmeti{
  public:
    predmeti_zapis zapis;
    predmeti *next;
};
 
class prijave_zapis{
  public:
    int sifra_prijave;
    int sifra_predmeta;
    int maticni_br;
    char rok[10];

    void unos(){}
    void ispis(){}
};

class prijave{
  public:
    prijave_zapis *prijavnica;
    prijave *next;

    // Koristiti konstruktor za dinamičku alokaciju vezanog objekta kod sadržavanja 
    // po referenci (metoda ispisuje tekst "Konstruktor"). 
    prijave(){
      cout << "Konstruktor" << endl;
      prijavnica = new prijave_zapis;
    }
};

predmeti predmet;
prijave *prijava;

int main(){



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
            predmet.zapis.input();
            predmet.zapis.ispis();
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