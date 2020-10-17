#include <iostream>
#include "biblioteka_vrijeme.cc"        
using namespace std;
 

struct pisac_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
    float vrijeme_unosa;
    pisac_t *next;
};


void add_to_list(pisac_t *head){
    pisac_t *novi, *zadnji;
    zadnji = head;

    while(zadnji->next){
        zadnji = zadnji->next;
    }

    novi = new pisac_t;
    zadnji->next = novi;
    novi->next = NULL;
    vrijeme_pocetak();
    cout << "Unesi sifru autora: ";
    cin >> novi->sifra;
    cout << "Unesi ima autora: ";
    unos(novi->ime_prez);
    cout << "Unesi naslov: ";
    unos(novi->naslov);
    vrijeme_kraj();
    novi->vrijeme_unosa = vrijeme_proteklo()/1000;
}



void ispis(pisac_t *head){
    int zbroj = 0;
    pisac_t *temp = head->next;
    while(temp != NULL){
        cout << "--------------------------------------------------------------------" << endl;
        cout << temp->sifra << "\t" << temp->ime_prez << "\t" << temp->naslov << "\t"
        << temp->vrijeme_unosa << endl;
        zbroj += temp->sifra;
        cout << "Sljedeca adresa: " << temp->next << endl;
        temp = temp->next;
    }
    cout << "Zbroj kljuceva: " << zbroj << endl;
}


void findNode(pisac_t *head, int sifra){
    while(head != NULL){
        if(head->sifra == sifra){
            cout << "-------------------------------------------------" << endl;
            cout << head->sifra << "\t" << head->ime_prez << "\t" << head->naslov << "\t"
            << head->vrijeme_unosa << endl;
            cout << "-------------------------------------------------" << endl;
            break;
        }
        else{
            head = head->next;
        }
        if(head == NULL){
            cout << "Nema takvog zapisa" << endl;
        }

    }
    
}

void deleteNode(pisac_t *head, int sifra){
    pisac_t *help = head->next, *prev = head;
    while(help != NULL){
        if(help->sifra == sifra){
            prev->next = help->next;
            delete help;
            cout << "Zapis obrisan" << endl;
            break;
        }
        else{
            prev = help;
            help = help->next;
        }
    }
    if(help == NULL){
        cout << "Nema elementa" << endl;
    }
}

int kljuc(){
    int sifra;
    cout << "Unesi sifru: ";
    cin >> sifra;
    return sifra;
}

int main(){

pisac_t *head = new pisac_t;
head->next = NULL;




int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Unos novog elementa vezane liste na kraj" << endl;
    cout << "2. Ispis sadržaja vezane liste zajedno sa zbrojem primatnih ključeva" << endl;
    cout << "3. Pretraživanje vezane liste (prema primarnom ključu)" << endl;
    cout << "4. Brisanje elemenata liste (prema primarnom ključu)" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            add_to_list(head);
            break;
        case 2:
            ispis(head);
            break;
        case 3:
            findNode(head, kljuc());
            break;
        case 4:
            deleteNode(head, kljuc());
            break;
    }
}while(jos != 9);
 
 
    return 0;
}
 