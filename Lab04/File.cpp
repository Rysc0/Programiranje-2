#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <fstream>
using namespace std;

struct data_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
    float vrijeme_unosa;
};

fstream file;
data_t dat;

void input(){
    // fstream file;
    file.open("dat.dat",ios::app | ios::binary);
    vrijeme_pocetak();
    cout << "Unesi sifru autora: ";
    cin >> dat.sifra;
    cout << "Unesi ime i prezime autora:";
    unos(dat.ime_prez);
    cout << "Unesi naslov djela: ";
    unos(dat.naslov);
    vrijeme_kraj();
    dat.vrijeme_unosa = vrijeme_proteklo()/100;
    file.write((char *)&dat,sizeof(dat));
    file.close();
    // file.clear();
}

int kljuc(){
    int sifra;
    cout << "Unesi kljuc: ";
    cin >> sifra;
    return sifra;
}

void provjera(){
    int sifra = kljuc();
    file.open("dat.dat", ios::in | ios::binary);
    if(file){
        while(1){
            file.read((char *)&dat,sizeof(dat));
            if(dat.sifra == sifra){
                cout << "Postoji zapis! Onemogucujem unos!" << endl;
                file.close();
                break;
            }
            else{ 
                if(!file.eof()) continue;
                else{
                    cout << "Ne postoji zapis, mozete unijeti novi!" << endl << "------------------" << endl;
                    file.close();
                    input();
                    break;
                }
            }
        }
    }  
    else cout << "Datoteka ne postoji!" << endl;
}

void ispis(){
    int zapis = 0;
    file.open("dat.dat", ios::in | ios::binary);
    if(file){
        cout << "Sifra\t" << "Autor\t" << "Naslov\t" << "Vrijeme unosa" << endl;
        while(1){
            file.read((char *)&dat,sizeof(dat));
            if(file.eof()) break;
            cout << dat.sifra << "\t" << dat.ime_prez << "\t" << dat.naslov << "\t" << dat.vrijeme_unosa << endl;
            zapis++;
        }
        file.close();
    }
    else{
        cout << "Datoteka ne postoji!" << endl;
        file.close();
    }
    cout << "Broj zapisa = " << zapis << endl;
}


void pretraga(){
    file.open("dat.dat", ios::in | ios::binary);
    if(file){
        int sifra = kljuc();
        while(1){
            file.read((char *)&dat,sizeof(dat));
            if(file.eof()){
                cout << "Nema zapisa!" << endl;
                break;
            }
            if(dat.sifra == sifra){
                cout << "Zapis nađen!" << endl;
                cout << dat.sifra << "\t" << dat.ime_prez << "\t" << dat.naslov << "\t" << dat.vrijeme_unosa << endl;
                break;
            }
            else{
                if(file.eof()){
                    cout << "Datoteka je prazna!" << endl;
                    break;
                }
            }
        }
    }
    else cout << "Datoteka ne postoji!" << endl;
    file.close();
}


int main(){

int jos;
// int jos_1;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "11. Unos podataka u datoteku " << endl;
    cout << "12. Provjera primarnog kljuca kod unosa u datoteku" << endl;
    cout << "2. Ispis sadrzaja cijele datoteke (ispisuju se svi atributi zapisa)" << endl;
    cout << "3. Pretrazivanje datoteke" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 11:
            input();
            break;
        case 12:
            provjera();
            break;
        case 2:
            ispis();
            break;
        case 3:
            pretraga();
            break;
    }
}while(jos != 9);
 
 
    return 0;
}