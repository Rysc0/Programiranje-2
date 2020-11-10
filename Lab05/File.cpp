#include <iostream>
// #include "biblioteka_vrijeme.cc"
#include "biblioteka_tel_imenik.cc"
#include <fstream>
using namespace std;
  
struct data_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
    double vrijeme_unosa; // na jednu decimalu točnosti
};

void makeFile(){
    // traži od korisnika unos veličine datoteke praznih zapisa
    // ako je uneseni broj prost ili manji od 10 upiši ponovno
    // mora se unijet broj koji nije prost i koji je veći od 9
    // kreirati datoteku praznih zapisa
    // izračunati i ispisati prvi manji prosti broj od veličine datoteke (unesenog broja)
}

void fileInput(){
    // adresa zapisa ovisi o vrijednosti primarnog ključa, uz uvažavanje duplikata 
    // (ako je zapis na izračunatoj adresi popunjen, tada se traži prvi prazni zapis radi upisa)
} 

void pretraga(){
    // unosi se vrijednost primarnog ključa. Ispisuju se svi atributi odgovarajućeg zapisa ako je nađen.
    // Ispisati poruku ako se na izračunatoj adresi nalazi duplikat traženog zapisa!
}

void statistika(){
    // a.) Statistika: ispisati ukupan broj praznih zapisa u relativnoj datoteci
    // b.) Statistika: ispisati ukupan broj nepraznih zapisa u relativnoj datoteci
    // c.) Statistika: ispisati zbroj svih primarnih ključeva u relativnoj datoteci
}

int main(){


int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Kreiranje datoteke praznih zapisa i racunajne prostog broja" << endl;
    cout << "2. Unos podataka u relativnu datoteku (uvazavajuci duplikate)" << endl;
    cout << "3. Pretrazivanje relativne datoteke uz prepoznavanje duplikata" << endl;
    cout << "4. Statistika" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            // function
            makeFile();
            break;
        case 2:
            // function
            fileInput();
            break;
        case 3:
            // function
            pretraga();
            break;
        case 4:
            // function
            statistika();
            break;
    }
}while(jos != 9);
 
 
    return 0;
}