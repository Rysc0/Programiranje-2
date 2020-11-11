#include <iostream>
// #include "biblioteka_vrijeme.cc"
#include "biblioteka_tel_imenik.cc"
#include <fstream>
#include <cmath>
using namespace std;
  
struct data_t{
    // int redni_br; ne treba jer ce sifra biti automatski i redni broj ??
    int sifra;
    char ime_prez[50];
    char naslov[50];
    double vrijeme_unosa; // na jednu decimalu točnosti
};

fstream file;
data_t podaci;

bool prost(int x){
    bool prime = true;
    for(int i = 2; i < sqrt(x); i++){
        if(x % i == 0){
            prime = false;
            return false;
        }
    }
    if(prime) return true;
    return 0;
}


int manjiProst(int x){
    int i,j;
    bool prost;
    for(i = x; i > 1; i--){
        prost = true;
        for(j = 2; j < sqrt(i); j++){
            if(i % j == 0){
                prost = false;
                break;
                }
        }
        if(prost) return i;
    }
    return 0;    
}

void makeFile(){
    // traži od korisnika unos veličine datoteke praznih zapisa
    // ako je uneseni broj prost ili manji od 10 upiši ponovno
    // mora se unijet broj koji nije prost i koji je veći od 9
    int zapisa;
    do{
        cout << "Koliko zapisa zelite? (Velicina datoteke): ";
        cin >> zapisa;
    }while(zapisa < 10 || prost(zapisa));

    // kreirati datoteku praznih zapisa
    podaci.ime_prez[0] = '\0';
    podaci.naslov[0] = '\0';
    file.open("file.dat", ios::out);
    for(int i = 1; i < zapisa; i++){
        podaci.sifra = i;
        file.write((char *)&podaci,sizeof(podaci));
    }

    // izračunati i ispisati prvi manji prosti broj od veličine datoteke (unesenog broja)
    cout << "Prvi manji prosti broj od velicine datoteke je: " << manjiProst(zapisa) << endl;
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
            // functionž
            cout << "PROST: " << prost(11) << endl;
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