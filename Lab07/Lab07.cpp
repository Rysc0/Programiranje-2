#include <iostream>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"
#include <fstream>
#include <iomanip>
using namespace std;
  
struct data_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
};

struct lista_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
    lista_t *next;
};

data_t zapis;
fstream file;
string name = "datoteka.dat";

bool fileCheck(){
    file.open(name);
    file.close();
    if(file) return true;
    else return false;
}

void createFile(){ 
    file.open(name,ios::out | ios::binary);
    file.close();
    cout << "File kreiran!" << endl;
}

void input(){

    if(!fileCheck()){
        createFile();
    }

    file.open(name,ios::app | ios::binary);
    cout << "Unesi sifru autora: ";
    cin >> zapis.sifra;
    cout << "Unesi ime autora: ";
    unos(zapis.ime_prez);
    cout << "Unesi naslov: ";
    unos(zapis.naslov);
    file.write((char *)&zapis,sizeof(zapis));

    file.close();
}


void generiranje(){
    if(fileCheck() == true){
    srand(time(NULL));
    float vrijeme_generiranja = 0;
    int number;
    cout << "Koliko zapisa: ";
    cin >> number;
    file.open(name,ios::app | ios::binary);
    vrijeme_pocetak();
    for(int i = 0; i < number; i++){
        zapis.sifra = rand()%1000+rand()%1000;
            
        // generiranje imena i prezimena
        zapis.ime_prez[0] = char(rand()%26+65);
        for(int j = 1; j < 6; j++){
            zapis.ime_prez[j] = char(rand()%26+97);
        }
        zapis.ime_prez[6] = ' ';
        zapis.ime_prez[7] = char(rand()%26+65);
        for(int j = 8; j < 12; j++){
            zapis.ime_prez[j] = char(rand()%26+97);
        }
        zapis.ime_prez[12] = '\0';

        // generiranje naslova
        zapis.naslov[0] = char(rand()%26+65);
        for(int i = 1; i < 20; i++){
            zapis.naslov[i] = char(rand()%26+97);
        }
        zapis.naslov[20] = '\0';   
            
        // zapis u datoteku
        file.write((char *)&zapis,sizeof(zapis));
    }
    vrijeme_kraj();
    file.close();
    cout << "Vrijeme generiranja: " << setprecision(4) << vrijeme_proteklo()/1000 << endl;
    }
    else cout << "File ne postoji!" << endl;
}


void dealokacija(lista_t *head){
    lista_t *current, *next;
    current = head->next;
    next = current->next;
    while(next){
        delete current;
        current = next;
        next = next->next;
    }
    head->next = NULL;
}

void copyFile(lista_t *head){
    if(fileCheck()){
        lista_t *novi;
        if(head->next) dealokacija(head);
        int redni_broj = 0;
        file.open(name,ios::in | ios::binary);
        while(1){
            file.read((char *)&zapis,sizeof(zapis));
            if(file.eof()) break;
            redni_broj++;
            cout << redni_broj << "\tPrimarni kljuc (sifra): " << zapis.sifra << endl;
            novi = new lista_t;
            head->next = novi;
            novi->next = NULL;
            novi->sifra = zapis.sifra;
            strcpy(novi->ime_prez,zapis.ime_prez);
            strcpy(novi->naslov,zapis.naslov);
            head = novi;
        }
        file.close();
    }
    else cout << "File ne postoji!" << endl;
}


void readList(lista_t *head){
    int redni_broj = 0;
    if(fileCheck()){
        cout << head << "\t" << head->next << endl;
        lista_t *current = head->next;
        while(current != NULL){
            redni_broj++;
            cout << redni_broj << "\t" << current->sifra << "\t" << current->ime_prez << "\t" << current->naslov << "\t" << current->next << endl;
            current = current->next;
        }
    }
    else cout << "File ne postoji!" << endl;
}


int main(){

lista_t *head;
head = new lista_t;
head->next = NULL;


int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Rucni unos zapisa u datoteku" << endl;
    cout << "2. Generiranje zapisa datoteke" << endl;
    cout << "3. Kopiranje sadrzaja datoteku u odgovarajucu vezanu listu" << endl;
    cout << "4. Ispis sadrzaja vezane liste" << endl;
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
            generiranje();
            break;
        case 3:
            // function
            copyFile(head);
            break;
        case 4:
            // function
            readList(head);
            break;
        case 5:
            cout << fileCheck() << endl;
    }
}while(jos != 9);
 
 
    return 0;
}